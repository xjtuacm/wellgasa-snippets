/*
@title: GCD 最大公约数
@method:
    RecursiveGCD: 递归版本
    IterativeGCD: 迭代版本
@description:
    用辗转相除法求两个数的最大公约数
@arguments:
    a, b: 两个正数
@return:
    两个数的最大公因数
@range:
    a > 0
    b > 0
@dependence: null
@performance:
    Time: O(log(min(a, b))) at worst
    Space:
        RecursiveGCD: O(log(min(a, b))) at worst
        IterativeGCD: O(1)
*/

// 递归 GCD
template <class T> T RecursiveGCD(T a, T b) {
  return b == 0 ? a : RecursiveGCD(b, a % b);
}

// 迭代 GCD
template <class T> T IterativeGCD(T a, T b) {
  while (b != 0) {
    a %= b;
#ifdef _MOVE_H
    // if include move.h or algorithm
    std::swap(a, b);
#else
    T temp = a;
    a = b;
    b = temp;
#endif
  }
  return a;
}

/*
@title: 多重迭代 GCD
@description:
    求若干个数的最大公约数
@arguments:
    array: 数组首地址
    N: 数组长度
@range:
    N > 0
    forall i in array: 
        i > 0
@dependence:
    IterativeGCD: 迭代GCD
@performance:
    Time: $O(N \log(\min_{i \in array}i)$ at worst
    Space: O(1)
@note:
    里面有一个gcd == 1 即短路的设定 (gcd != 1)
*/
template <class T> T IterativeMultiGCD(T *array, int N) {
  T gcd = array[0];
  for (int i = 1; i < N && gcd != 1; i++) {
    gcd = IterativeGCD(gcd, array[i]);
  }
  return gcd;
}