#pragma once

// Time: O(logN)
// Space: O(1)

class Solution {
public:
  static int trailingZeroes(int n) {
    int ans = 0;
    while (n) {
      n /= 5;
      ans += n;
    }
    return ans;
  }
};
