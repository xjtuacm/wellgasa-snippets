/*
@title: 筛法求欧拉函数
@description:
    欧拉函数 phi(n): [1, n] 中与 n 互质的数的数目
@arguments:
    n: 求 [1, n] 范围内的欧拉函数
    phi: 欧拉函数容器 [alloc only]
        accessable in [1, n]
    prime: 质数容器 [alloc only]
        accessable in [0, π(n))
    isPrime: 是否为质数 [alloc only]
        accessable in [0, max(1, n)]
@performance:
    Time: O(n)
    Space: O(n)
@return:
    [int] π(n)
@dependence:
    memset in "cstring"
@note:
    函数外访问isPrime[x] 等价于 "x 是质数" 的真假性
*/
int Sieve(int n, int *phi, int *prime, bool *isPrime) {
  // initialize
  int cnt = 0;
  memset(isPrime, false, 2); // 为了isPrime 的一致性，若不利用 isPrime 可去之
  memset(isPrime + 2, true, n - 2); // init isPrime[2, n) = true
  phi[1] = 1;
  // sieve
  for (int i = 0; i <= n; i++) {
    if (isPrime[i]) {
      prime[cnt++] = i;
      phi[i] = i - 1;
    }
    for (int j = 0; j < cnt; j++) {
      int next = i * prime[j];
      if (next > n) {
        break;
      }
      isPrime[next] = false;
      if (i % prime[j] == 0) {
        phi[next] = phi[i] * prime[j];
        break;
      } else {
        phi[next] = phi[i] * (prime[j] - 1);
      }
    }
  }
  return cnt;
}
