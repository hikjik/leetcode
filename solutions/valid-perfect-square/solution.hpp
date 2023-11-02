#pragma once

// Time:
// Space:

class Solution {
public:
  static bool isPerfectSquare(int num) {
    int left = 1;
    int right = num;

    while (left <= right) {
      const long long middle = left + (right - left) / 2;
      const auto square = middle * middle;
      if (square == num) {
        return true;
      } else if (square > num) {
        right = middle - 1;
      } else {
        left = middle + 1;
      }
    }

    return false;
  }
};
