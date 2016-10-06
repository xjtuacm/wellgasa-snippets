/*
 * @title: Rader Algorithm
 * @description: Binary Index Reverse, using in Iterative FFT/NTT
 * @arguments:
 *    data: buffer of data
 *    n: number of data
 *      must be power of 2
 * @performance:
 *    Time: O(n log(n))
 *    Space: O(n)
 *      Extra: O(1)
 * @return: void
 * @dependence:
 *    std::swap in "algorithm"
 * @note:
 *    常用于迭代FFT与NTT中的倒位序变换
 */
#pragma once
#include <algorithm>
template <class T> void Rader(T *data, int n) {
  int j = n >> 1;
  for (int i = 1; i < n - 1; i++) {
    if (i < j) {
      std::swap(data[i], data[j]);
    }
    int k = n >> 1;
    while (j >= k) {
      j -= k;
      k >>= 1;
    }
    if (j < k) {
      j += k;
    }
  }
}
