/*
 * @title: Fast Fourier Transform
 * @description: Iterative FFT
 * @arguments: 
 *   data: coefficient array
 *   n: the size of data
 *      must be power of 2
 *   isInversed: is it Inversed Transform?
 * @return: void
 * @dependence:
 *    std::swap in <algorithm>
 *    std::complex in <complex>
 *    Rader in "Rader.cpp"
 *    std::cos, std::sin, std::acos in <cmath>
 * @note:
 *    原地变换迭代FFT，但注意精度误差。
 */
#pragma once
#include <cmath>
#include <complex>
#include <algorithm>
#include "Rader.cpp"

const double PI = std::acos(-1.0);

typedef std::complex<double> CT;
void transform(CT *data, int n, bool isInversed = false) {
  int on = isInversed? -1: 1;
  Rader(data, n);
  for(int len = 2; len <= n; len <<= 1) {
    double delta = -on * 2 * PI / len;
    CT wn(std::cos(delta), std::sin(delta));
    for (int j = 0; j < n; j += len) {
      CT w(1, 0);
      for (int k = j; k < j + len / 2; k++) {
        CT u = data[k];
        CT t = w * data[k + len / 2];
        data[k] = u + t;
        data[k + len / 2] = u - t;
        w *= wn;
      }
    }
  }
  if (isInversed) {
    for (int i = 0; i < n; i++) {
      data[i] /= n;
    }
  }
}

