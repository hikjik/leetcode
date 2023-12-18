#pragma once

#include <climits>
#include <ranges>
#include <vector>

// Time: O(N)
// Space: O(1)

namespace stl {

// Time: O(N)
// Space: O(N)
class Solution {
public:
  static int maxProductDifference(std::vector<int> nums) {
    std::ranges::nth_element(nums, nums.begin() + 2);
    const auto minProduct = nums[0] * nums[1];
    std::ranges::nth_element(nums, nums.begin() + 2, std::greater{});
    const auto maxProduct = nums[0] * nums[1];
    return maxProduct - minProduct;
  }
};

} // namespace stl

namespace one_pass {

// Time: O(N)
// Space: O(1)
class Solution {
public:
  static int maxProductDifference(const std::vector<int> &nums) {
    int min1 = INT_MAX, min2 = INT_MAX;
    int max1 = INT_MIN, max2 = INT_MIN;
    for (auto num : nums) {
      if (num > max1) {
        max2 = std::exchange(max1, num);
      } else if (num > max2) {
        max2 = num;
      }

      if (num < min1) {
        min2 = std::exchange(min1, num);
      } else if (num < min2) {
        min2 = num;
      }
    }
    return max1 * max2 - min1 * min2;
  }
};

} // namespace one_pass
