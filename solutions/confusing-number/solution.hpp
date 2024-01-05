#pragma once

// Time: O(logN)
// Space: O(1)

class Solution {
public:
  static bool confusingNumber(int n) {
    int r = 0;
    for (int i = n; i; i /= 10) {
      const auto d = i % 10;
      if (2 <= d && d <= 5 || d == 7) {
        return false;
      }
      r *= 10;
      if (d == 6 || d == 9) {
        r += 15 - d;
      } else {
        r += d;
      }
    }
    return r != n;
  }
};
