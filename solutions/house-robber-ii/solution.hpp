#pragma once

#include <algorithm>
#include <span>
#include <vector>

// Time: O(N)
// Space: O(1)

class Solution {
public:
  static int rob(const std::vector<int> &nums) {
    auto view = std::span{nums};
    return std::max({
        nums[0], // case nums.size() == 1
        rob(view.subspan(0, nums.size() - 1)),
        rob(view.subspan(1)),
    });
  }

private:
  // 198. House Robber
  // https://leetcode.com/problems/house-robber/
  static int rob(std::span<const int> nums) {
    int a = 0, b = 0;
    for (auto num : nums) {
      std::swap(a, b);
      b = std::max(b + num, a);
    }
    return b;
  }
};
