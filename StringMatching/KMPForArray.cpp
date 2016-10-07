/*
 * @title: KMP 串匹配
 * @description: KMP 字符串匹配算法
 * @arguments:
 *  S: 源串的首指针
 *  n: 源串的长度
 *  P: 模式串的首指针
 *  m: 模式串的长度
 *  N: Next 数组 [alloc only]
 * @performance:
 *  Time: O(|P| + |S|)
 *  Space: O(|S| + |P| + |N|)
 *    Extra: O(|N|)
 * @dependence:
 *  Matched(int index);
 */

void KMPInit(int *P, int n, int *N) {
  int k = N[0] = 0;
  for (int i = 1; i < n; i++) {
    while (k && P[k] != P[i]) {
      k = N[k - 1];
    }
    if (P[k] == P[i]) {
      k++;
    }
    N[i] = k;
  }
}

void KMP(int *S, int n, int *P, int m, int *N) {
  int k = 0;
  for (int i = 0; i < n; i++) {
    while (k && P[k] != S[i]) {
      k = N[k - 1];
    }
    if (P[k] == S[i]) {
      k++;
    }
    if (k == m) {
      Matched(i);
      k = N[k - 1];
    }
  }
}
