#pragma once

#include <ranges>
#include <string>
#include <vector>

// Time: O(1)
// Space: O(1)

class Solution {
public:
  static std::string triangleType(std::vector<int> nums) {
    std::ranges::sort(nums);
    if (nums[0] + nums[1] <= nums[2]) {
      return "none";
    }
    if (nums[0] == nums[1] && nums[1] == nums[2]) {
      return "equilateral";
    }
    if (nums[0] == nums[1] || nums[1] == nums[2]) {
      return "isosceles";
    }
    return "scalene";
  }
};
