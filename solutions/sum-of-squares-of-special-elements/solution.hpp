#pragma once

#include <vector>

// Time:
// Space:

class Solution {
public:
  static int sumOfSquares(const std::vector<int> &nums) {
    const int n = nums.size();

    int sum = 0;
    for (int i = 1; i <= n; ++i) {
      if (n % i == 0) {
        sum += nums[i - 1] * nums[i - 1];
      }
    }
    return sum;
  }
};
