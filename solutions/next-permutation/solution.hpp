#pragma once

#include <algorithm>
#include <vector>

// Time: O(N)
// Space: O(1)

namespace linear {

// Time: O(N)
// Space: O(1)
class Solution {
public:
  static void nextPermutation(std::vector<int> &nums) {
    auto left = std::is_sorted_until(nums.rbegin(), nums.rend());
    if (left != nums.rend()) {
      auto right = std::upper_bound(nums.rbegin(), left, *left);
      std::iter_swap(left, right);
    }
    std::reverse(left.base(), nums.end());
  }
};

} // namespace linear

namespace stl {

// Time: O(N)
// Space: O(1)
class Solution {
public:
  static void nextPermutation(std::vector<int> &nums) {
    std::next_permutation(nums.begin(), nums.end());
  }
};

} // namespace stl
