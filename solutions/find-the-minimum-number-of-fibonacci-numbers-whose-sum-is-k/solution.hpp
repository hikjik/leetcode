#pragma once

#include <vector>

// Time: O(logK)
// Space: O(1)

class Solution {
public:
  static int findMinFibonacciNumbers(int k) {
    int a = 1, b = 1;
    while (b <= k) {
      a = std::exchange(b, a + b);
    }

    int cnt = 0;
    while (a) {
      if (a <= k) {
        k -= a;
        ++cnt;
      }
      b = std::exchange(a, b - a);
    }
    return cnt;
  }
};
