#pragma once

#include <vector>

class Solution {
public:
  static std::vector<int> runningSum(const std::vector<int> &nums) {
    std::vector<int> running_sum(nums);
    for (size_t i = 1; i < nums.size(); ++i) {
      running_sum[i] += running_sum[i - 1];
    }
    return running_sum;
  }
};
