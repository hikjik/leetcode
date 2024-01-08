#pragma once

#include <vector>

// Time: O(logN)
// Space: O(1)

namespace linear {

// Time: O(N)
// Space: O(1)
class Solution {
public:
  static int missingElement(const std::vector<int> &nums, int k) {
    for (int i = 0; i + 1 < std::ssize(nums); ++i) {
      const auto gap = nums[i + 1] - nums[i] - 1;
      if (gap >= k) {
        return nums[i] + k;
      }
      k -= gap;
    }
    return nums.back() + k;
  }
};

} // namespace linear

namespace bs {

// Time: O(logN)
// Space: O(1)
class Solution {
public:
  static int missingElement(const std::vector<int> &nums, int k) {
    int l = 0, r = nums.size() - 1;
    while (l < r) {
      const auto m = l + (r - l + 1) / 2;
      nums[m] - nums[0] - m >= k ? r = m - 1 : l = m;
    }
    return nums[0] + k + l;
  }
};

} // namespace bs
