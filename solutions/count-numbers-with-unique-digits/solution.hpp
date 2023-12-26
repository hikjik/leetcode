#pragma once

// Time: O(N)
// Space: O(1)

class Solution {
public:
  static int countNumbersWithUniqueDigits(int n) {
    if (n == 0) {
      return 1;
    }
    int ans = 10;
    for (int u = 9, d = 9; n-- > 1; --u) {
      ans += d *= u;
    }
    return ans;
  }
};
