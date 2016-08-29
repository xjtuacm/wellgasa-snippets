/*
@title: 线性筛法求莫比乌斯函数
@description:
    O(n)预处理 [1, n] 范围内的莫比乌斯函数的值
@arguments:
    n: 数据规模
    mobius: 莫比乌斯函数缓存首地址 [alloc only]
    prime: 素数缓存首地址 [alloc only]
    isPrime: 判断素数缓存首地址 [alloc only]
@performance:
    Time: O(n)
    Space: O(n)
@range:
    |mobius| >= n + 1
    |isPrime| >= n + 1
@dependence:
    memset in "cstring"
@note:
    这可以顺便筛出素数
    mobius 是一个数论函数，因此不会也不能访问 mobius[0]
    isPrime 也是一个数论函数，因此不会也不能访问 isPrime[0]
*/

void LinearSieveMobius(int n, int *mobius, int *prime, bool *isPrime) {
  // initialize
  int cnt = 0;
  memset(isPrime, false, 2);
  memset(isPrime + 2, true, n - 2);
  mobius[1] = 1;
  // sieve
  for (int i = 2; i < n; i++) {
    if (isPrime[i]) {
      prime[cnt++] = i;
      mobius[i] = -1;
    }
    for (int j = 0; j < cnt; j++) {
      int next = i * prime[j];
      if (next > n) {
        break;
      }
      isPrime[next] = false;
      if (i % prime[j] == 0) {
        mobius[next] = 0;
        break;
      } else {
        mobius[next] = -mobius[i];
      }
    }
  }
}
