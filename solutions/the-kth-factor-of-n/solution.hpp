#pragma once

// Time: O(N^(0.5))
// Space: O(1)

class Solution {
public:
  static int kthFactor(int n, int k) {
    int d = 1;
    for (; d * d < n; ++d) {
      if (n % d == 0 && !--k) {
        return d;
      }
    }
    for (d = n / d; d; --d) {
      if (n % d == 0 && !--k) {
        return n / d;
      }
    }
    return -1;
  }
};
