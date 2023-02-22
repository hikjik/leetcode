#pragma once

class Solution {
public:
  static int arrangeCoins(int n) {
    auto left = 1, right = n;
    while (left <= right) {
      long long middle = left + (right - left) / 2;
      long long sum = (middle + 1) * middle / 2;

      if (sum == n) {
        return middle;
      } else if (sum > n) {
        right = middle - 1;
      } else {
        left = middle + 1;
      }
    }
    return left - 1;
  }
};
