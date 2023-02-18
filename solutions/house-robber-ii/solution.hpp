#pragma once

#include <algorithm>
#include <vector>

class Solution {
public:
  static int rob(const std::vector<int> &nums) {
    return std::max(nums.front() + rob_no_cycles(nums, 2, nums.size() - 1),
                    rob_no_cycles(nums, 1, nums.size()));
  }

private:
  static int rob_no_cycles(const std::vector<int> &nums, size_t start,
                           size_t end) {
    int a = 0, b = 0, c = 0;
    for (size_t i = start; i < end; ++i) {
      const auto d = std::max(nums[i] + a, nums[i] + b);
      a = b, b = c, c = d;
    }
    return std::max(b, c);
  }
};
