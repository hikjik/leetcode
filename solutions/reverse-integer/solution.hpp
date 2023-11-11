#pragma once

#include <climits>

// Time: O(logN)
// Space: O(1)

class Solution {
public:
  static int reverse(int n) {
    int ans = 0;
    for (int i = n; i; i /= 10) {
      if (ans > INT_MAX / 10 || ans < INT_MIN / 10) {
        return 0;
      }
      ans = ans * 10 + i % 10;
    }
    return ans;
  }
};
