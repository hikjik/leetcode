#pragma once

class Solution {
public:
  static int mySqrt(int n) {
    int left = 0, right = n;
    while (left <= right) {
      const long long middle = left + (right - left) / 2;
      const auto square = middle * middle;

      if (square == n) {
        return middle;
      }
      if (square > n) {
        right = middle - 1;
      } else {
        left = middle + 1;
      }
    }

    return right;
  }
};