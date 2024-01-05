#pragma once

#include <vector>

// Time: O(N)
// Space: O(1)

class Solution {
public:
  static std::vector<std::vector<int>>
  findMissingRanges(const std::vector<int> &nums, int lower, int upper) {
    if (nums.empty()) {
      return {{lower, upper}};
    }

    std::vector<std::vector<int>> ans;
    if (nums.front() - lower) {
      ans.push_back({lower, nums.front() - 1});
    }
    for (int i = 1; i < std::ssize(nums); ++i) {
      if (nums[i] - nums[i - 1] > 1) {
        ans.push_back({nums[i - 1] + 1, nums[i] - 1});
      }
    }
    if (upper - nums.back()) {
      ans.push_back({nums.back() + 1, upper});
    }
    return ans;
  }
};
