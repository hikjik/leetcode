#pragma once

// Time: O(logN)
// Space: O(1)

class Solution {
public:
  static int mySqrt(int n) {
    int left = 1, right = n;
    while (left <= right) {
      const auto middle = left + (right - left) / 2;
      middle > n / middle ? right = middle - 1 : left = middle + 1;
    }
    return right;
  }
};
