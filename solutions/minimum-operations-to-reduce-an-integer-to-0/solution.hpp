#pragma once

// Time: O(logN)
// Space: O(1)

class Solution {
public:
  static int minOperations(int n) {
    int ans = 0;
    while (n) {
      if (n & 1) {
        (n & 3) == 3 ? ++n : --n;
        ++ans;
      } else {
        n >>= 1;
      }
    }
    return ans;
  }
};
