#pragma once

#include <algorithm>
#include <vector>

// Time: O(N)
// Space: O(1)

namespace stl {

// Time: O(N)
// Space: O(N
class Solution {
public:
  static int maxProduct(std::vector<int> nums) {
    std::partial_sort(nums.begin(), nums.begin() + 2, nums.end(),
                      std::greater{});
    return (nums[0] - 1) * (nums[1] - 1);
  }
};

} // namespace stl

namespace one_pass {

// Time: O(N)
// Space: O(1)
class Solution {
public:
  static int maxProduct(const std::vector<int> &nums) {
    int max1 = 0, max2 = 0;
    for (auto num : nums) {
      if (num > max1) {
        max2 = max1;
        max1 = num;
      } else if (num > max2) {
        max2 = num;
      }
    }
    return (max1 - 1) * (max2 - 1);
  }
};

} // namespace one_pass
