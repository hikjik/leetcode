#pragma once

#include <cmath>

class Solution {
public:
  static int countTriples(int n) {
    int cnt = 0;
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= n; ++j) {
        const auto sum = i * i + j * j;
        const int k = std::sqrt(sum);
        if (k <= n && k * k == sum) {
          ++cnt;
        }
      }
    }
    return cnt;
  }
};
