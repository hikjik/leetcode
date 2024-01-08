#pragma once

#include <algorithm>
#include <ranges>
#include <vector>

// Time: O(logN)
// Space: O(1)

namespace one_line {

// Time: O(N)
// Space: O(1)
class Solution {
public:
  static bool isMajorityElement(const std::vector<int> &nums, int target) {
    return std::ranges::count(nums, target) > std::ssize(nums) / 2;
  }
};

} // namespace one_line

namespace bs {

// Time: O(logN)
// Space: O(1)
class Solution {
public:
  static bool isMajorityElement(const std::vector<int> &nums, int target) {
    // LeetCode Compile Error
    // return std::ranges::equal_range(nums, target).size() > nums.size() / 2;

    const auto [l, r] = std::equal_range(nums.begin(), nums.end(), target);
    return r - l > std::ssize(nums) / 2;
  }
};

} // namespace bs
