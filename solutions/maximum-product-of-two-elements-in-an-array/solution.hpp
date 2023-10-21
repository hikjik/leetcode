#pragma once

#include <algorithm>
#include <vector>

class Solution {
public:
  static int maxProduct(std::vector<int> nums) {
    std::partial_sort(nums.begin(), nums.begin() + 2, nums.end(),
                      std::greater<>());
    return (nums[0] - 1) * (nums[1] - 1);
  }
};
