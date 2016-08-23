// 自适应辛普森积分
// 依赖
//   double f(double x)
//     被积函数
//   double simpeps
//     误差限
// 参数
//   l 下界
//   h 上界

// // 测试
// #include<cmath>
// #include<cstdio>
// const double simpeps = 1e-10;
//
// double f(double x){
//   return 1 / x / x;
// }

// 模板代码开始
#include <cmath>

inline double simpson(double l, double h){
  return (h - l) * (f(l) + 4 * f((l + h) / 2) + f(h)) / 6;
}

inline double adaptsimp(double l, double h){
  double a = simpson(l, (l + h) / 2);
  double b = simpson((l + h) / 2, h);
  double c = simpson(l, h);
  if(fabs(a + b - c) > 15 * simpeps){
    a = adaptsimp(l, (l + h) / 2);
    b = adaptsimp((l + h) / 2, h);
  }
  return a + b;
}
// 模板代码结束

// // 测试
// int main(){
//   printf("%lf\n", adaptsimp(1, 1e100));
// }
