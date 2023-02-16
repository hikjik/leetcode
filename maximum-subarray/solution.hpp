#pragma once

#include <algorithm>
#include <numeric>
#include <vector>

class Solution {
public:
  static int maxSubArray(const std::vector<int> &nums) {
    int max_sum = std::numeric_limits<int>::min();

    int sum = 0;
    for (auto num : nums) {
      sum = std::max(sum + num, num);
      max_sum = std::max(max_sum, sum);
    }

    return max_sum;
  }
};
