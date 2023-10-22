#pragma once

#include <algorithm>
#include <vector>

class Solution {
public:
  static int maxProductDifference(std::vector<int> nums) {
    std::partial_sort(nums.begin(), nums.begin() + 2, nums.end());
    const auto min_product = nums[0] * nums[1];
    std::partial_sort(nums.begin(), nums.begin() + 2, nums.end(),
                      std::greater<>());
    const auto max_product = nums[0] * nums[1];
    return max_product - min_product;
  }
};
