// test status: accepted
#include <cstdio>
#include <iostream>
#include <cassert>
#include "ExtendedEuclid.cpp"

#define Pr(x) #x << " = " << x << std::endl
bool isAccepted(int (*algo)(int, int, int&, int&), int n) {
  int x, y;
  for (int a = 0; a < n; a++) {
    for (int b = 0; b < n; b++) {
      int gcd = algo(a, b, x, y);
      if (a * x + b * y != gcd) {
        std::cout << Pr(a) << Pr(b) << Pr(x) << Pr(y) << Pr(gcd);
        return false;
      }
      if (a == 0 && b == 0) {
        if (gcd != 0) {
          return false;
        }
      } else {
        if (a % gcd != 0 || b % gcd != 0) {
          return false;
        }
      }
    }
  }
  return true;
}

int main() {
  // pretest
  int pretestSize = 1000;
  if(isAccepted(ExtendedEuclid,pretestSize)) {
    std::cout << "ExtendedEuclid Passing pretest" << std::endl;
  }
  if(isAccepted(_ExtendedEuclid,pretestSize)) {
    std::cout << "_ExtendedEuclid Passing pretest" << std::endl;
  }
  // manually test
  int a, b, x, y;
  while (std::cin >> a >> b) {
    int gcd = ExtendedEuclid(a, b, x, y);
    std::cout << Pr(x) << Pr(y) << Pr(gcd) << Pr((a * x + b * y == gcd));
  }
  return 0;
}
