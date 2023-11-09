#pragma once

#include <vector>

// Time: O(N)
// Space: O(1)

class Solution {
public:
  static std::vector<int> twoSum(const std::vector<int> &nums, int target) {
    int left = 0, right = nums.size() - 1;
    while (left < right) {
      const auto sum = nums[left] + nums[right];
      if (sum == target) {
        return {left + 1, right + 1};
      }
      sum > target ? --right : ++left;
    }
    return {};
  }
};
