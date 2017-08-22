#include <bits/stdc++.h>
using namespace std;

const double eps = 1e-8;
const double pi = 3.1415926535897932384626433832795028842;

// 三态函数
inline int sgn(double x){
  if(x < -eps) return -1;
  if(x > eps) return 1;
  return 0;
}

// 二维向量
struct vec2{
  double x;
  double y;
  vec2() = default;
  vec2(double x, double y): x(x), y(y){}

  // 加减数乘
  vec2 operator+ (const vec2& v2) const{
    return vec2(x + v2.x, y + v2.y);
  }
  vec2 operator- (const vec2& v2) const{
    return vec2(x - v2.x, y - v2.y);
  }
  vec2 operator* (double r) const{
    return vec2(x * r, y * r);
  }

  // 点乘叉乘
  double dot(const vec2& v2) const{
    return x * v2.x + y * v2.y;
  }
  double cross(const vec2& v2) const{
    return x * v2.y - y * v2.x;
  }

  // 求夹角
  // s to e, counter clock
  double deg(const vec2& v2) const{
    return asin(cross(v2) / len() / v2.len());
  }

  // 求极角
  double theta() const{
    return (y > 0) ? atan2(y, x) : (2 * pi + atan2(y, x));
  }

  // 求长度
  double len() const{
    return hypot(x, y);
  }

  // 求单位向量
  vec2 norm() const{
    return vec2(x / len(), y / len());
  }

  // 逆时针旋转
  vec2 ccrotate(double deg) const{
    return vec2(x * cos(deg) - y * sin(deg), x * sin(deg) + y * cos(deg));
  }

  // 凸包排序
  bool operator< (const vec2& p2) const{
    if(sgn(x - p2.x) == -1) return true;
    else if(sgn(x - p2.x) == 0 && sgn(y - p2.y) == -1) return true;
    else return false;
  }
};

// 线段
struct seg{
  vec2 s;
  vec2 e;
  seg() = default;
  seg(const vec2& s, const vec2& e): s(s), e(e){}

  // 方向向量
  inline vec2 vec() const{
    return e - s;
  }

  // 点的投影
  vec2 proj(const vec2& v2) const{
    double r = (v2 - s).dot(vec()) * (1 / vec().len());
    return s + vec().norm() * r;
  }

  // 判断是否在直线上
  bool online(const vec2& v2) const{
    return sgn((v2 - s).cross(v2 - e)) == 0;
  }

  // 判断是否在s出发的射线上
  bool onhalfline(const vec2& v2) const{
    return online(v2) && sgn(vec().dot(v2 - s)) >= 0;
  }

  // 判断是否在线段上
  bool onseg(const vec2& v2) const{
    return online(v2) && sgn((v2 - s).dot(v2 - e)) <= 0;
  }
};

// 求凸包
void convexhull(vector<vec2>& vp, vector<vec2>& rp){
  rp.clear();
  sort(vp.begin(), vp.end());

  // 求下凸壳
  rp.push_back(vp[0]);
  rp.push_back(vp[1]);
  for(int i = 2; i < (int)vp.size(); i++){
    while( rp.size() >= 2 && sgn ( (rp[rp.size() - 1] - rp[rp.size() - 2]) .cross (vp[i] - rp[rp.size() - 2]) ) == -1 ){
      rp.pop_back();
    }
    rp.push_back(vp[i]);
  }

  // 求上凸壳
  int sz = rp.size() - 1;
  rp.push_back(vp[vp.size() - 2]);
  for(int i = vp.size() - 3; i >= 0; i--){
    while( rp.size() - sz >= 2 && sgn ( (rp[rp.size() - 1] - rp[rp.size() - 2]) .cross (vp[i] - rp[rp.size() - 2]) ) == -1 ){
      rp.pop_back();
    }
    rp.push_back(vp[i]);
  }

  // 凸包序
  //      3
  // 0(4)   2
  //      1
}
