/*
@title: 埃拉托斯特尼筛法
@arguments:
    n: 数据区间 [1, n]
    prime: 质数容器 [alloc only]
        writable in [0, π(n)]
    isPrime: 是否为质数 [alloc only]
        writable in [0, max(1, n)]
@performance:
    Time: O(n)
    Space: O(n)
@return:
    [int] [1, n] 范围内质数的个数
@dependence:
    memset in "cstring"
@note:
    prime[0] ~ prime[@return - 1] 是可以访问的
    函数外访问isPrime[x] 等价于 "x 是质数" 的真假性
*/
int Sieve(int n, int *prime, bool *isPrime) {
  // initialize
  int cnt = 0;
  memset(isPrime, false, 2);
  memset(isPrime + 2, true, n - 2);
  // sieve
  for (int i = 0; i <= n; i++) {
    if (isPrime[i]) {
      prime[cnt++] = i;
    }
    for (int j = 0; j < cnt; j++) {
      int next = i * prime[j];
      if (next > n) {
        break;
      }
      isPrime[next] = false;
      if (i % prime[j] == 0) {
        break;
      } else {
        continue;
      }
    }
  }
  return cnt;
}