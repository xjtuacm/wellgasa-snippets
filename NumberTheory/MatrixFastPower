#include <bits/stdc++.h>
using namespace std;

const int md = 1e9 + 7;

template<int sz, class T>
class Mat {

public:
  array<array<T, sz>, sz> data;

  Mat() = default;
  Mat(initializer_list<T> flatdata) {
    auto iter = flatdata.begin();
    for(int i = 0; i < sz; i++) {
      for(int j = 0; j < sz; j++) {
        data[i][j] = (*iter);
        iter++;
      }
    }
  }

  void clear(T x) {
    for(int i = 0; i < sz; i++) {
      for(int j = 0; j < sz; j++) {
        data[i][j] = x;
      }
    }
  }

  Mat<sz, T> operator* (const Mat<sz, T>& Mat2) const {
    Mat<sz, T> ret;
    ret.clear(0);
    for(int i = 0; i < sz; i++) {
      for(int j = 0; j < sz; j++) {
        for(int k = 0; k < sz; k++) {
          ret.data[i][j] += data[i][k] * Mat2.data[k][j];
          ret.data[i][j] %= md;
        }
      }
    }
    return ret;
  }

  Mat<sz, T> pow(long long n) const {
    Mat<sz, T> cur = (*this);
    Mat<sz, T> ret = Mat<sz, T>::identity();
    while(n) {
      if(n & 1) ret = ret * cur;
      n >>= 1;
      cur = cur * cur;
    }
    return ret;
  }

  static Mat<sz, T> identity() {
    Mat<sz, T> ret;
    ret.clear(0);
    for(int i = 0; i < sz; i++) {
      ret.data[i][i] = 1;
    }
    return ret;
  }
};

int main() {
  int a, b, c, t;
  long long n;
  while (scanf("%d%d%d%d%lld", &a, &b, &c, &t, &n) == 5) {
    Mat<3, long long> m1{
      t, 0, 0,
      t, 0, 0,
      t, 0, 0,
    };
    Mat<3, long long> m2{
      0, 1, 0,
      0, 0, 1,
      c, b, a,
    };
    printf("%lld\n", (m2.pow(n - 1) * m1).data[0][0]);
  }
  return 0;
}
