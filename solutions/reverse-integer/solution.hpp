#pragma once

#include <climits>

// Time: O(logN)
// Space: O(1)

class Solution {
public:
  static int reverse(int n) {
    int ans = 0;
    while (n) {
      const auto r = n % 10;
      if (ans > INT_MAX / 10 || ans < INT_MIN / 10) {
        return 0;
      }
      ans = ans * 10 + r;
      n /= 10;
    }
    return ans;
  }
};
