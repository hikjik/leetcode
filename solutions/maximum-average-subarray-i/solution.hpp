#pragma once

#include <algorithm>
#include <limits>
#include <vector>

// Time:
// Space:

class Solution {
public:
  static double findMaxAverage(const std::vector<int> &nums, int k) {
    int max_sum = std::numeric_limits<int>::min();
    int sum = 0;
    for (size_t i = 0; i < nums.size(); ++i) {
      sum += nums[i];
      if (i >= k - 1UL) {
        max_sum = std::max(max_sum, sum);
        sum -= nums[i + 1 - k];
      }
    }
    return max_sum * 1.0 / k;
  }
};
