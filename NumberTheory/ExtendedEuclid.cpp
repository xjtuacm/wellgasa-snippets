/*
@title: 拓展欧几里得算法
@description:
    使用辗转相除法求GCD时，同时求出满足
        a * x + b * y == gcd(a, b)
    的(x, y)
@arguments:
    a, b: 两个不同时为零的整数
    x, y: 两个整数容器 [alloc only]
@performance:
    Time: O(log(n))
    Space: O(log(n))
@return:
    [T = int] gcd(a, b) in [1, max(a, b)]
@note:
    gcd(0, 0) 是未定义的，这个实现会返回 0
    gcd(a, m) == 1 等价于 a 有模m乘法的逆元
    调用 ExtendedEuclid(a, m, x, y) 后 x 等于该逆元
    e.g. ExtendedEuclid(a, m, x, y) == 1? (x mod m): -1
*/

// one implementation
int ExtendedEuclid(int a, int b, int &x, int &y) {
  if (b == 0) {
    x = 1, y = 0;
    return a;
  }
  int gcd = ExtendedEuclid(b, a % b, y, x);
  y -= a / b * x;
  return gcd;
}

// another implementation
int _ExtendedEuclid(int a, int b, int &x, int &y) {
  if (b == 0) {
    x = 1, y = 0;
    return a;
  }
  int gcd = _ExtendedEuclid(b, a % b, x, y);
  int t = x;
  x = y;
  y = t - a / b * y;
  return gcd;
}

