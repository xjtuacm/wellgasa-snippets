/*
@title: KMP 字符串匹配
@description:
    KMP 字符串匹配算法
@arguments:
    S: 源串的首指针
    P: 模式串的首指针
    N: Next 数组
@performance:
    Time: O(|P| + |S|)
    Space: O(|S| + |P| + |N|)
        Extra: O(|N|)
@dependence:
    Matched(int i);
        过程Matched用于处理每一次匹配的结果，传入 i 为 匹配位置
        如每一个匹配后的统计、或者输出匹配位置……
@note:
    S 与 P 的终止符为'\0'
    N 无须在函数体外初始化
        因为预处理时保证不读取未初始化的部分

*/
// KMP应用N数组进行匹配
void KMP(char *S, char *P, int *N) {
  // 预处理
  int k = N[0] = 0;
  for (int i = 1; P[i]; i++) {
    while (k && P[i] != P[k]) {
      k = N[k - 1];
    }
    if (P[i] == P[k]) {
      k++;
    }
    N[i] = k;
  }
  // 匹配
  k = 0;
  for (int i = 0; S[i]; i++) {
    while (k && P[k] != S[i]) {
      k = N[k - 1];
    }
    if (P[k] == S[i]) {
      k++;
    }
    if (!P[k]) {
      Matched(i);
    }
  }
}
