#pragma once

#include <climits>
#include <ranges>
#include <unordered_set>
#include <vector>

// Time: O(N)
// Space: O(N)

class Solution {
public:
  static bool isConsecutive(const std::vector<int> &nums) {
    const auto [min, max] = std::ranges::minmax(nums);
    return max - min + 1 == std::ssize(nums) &&
           std::unordered_set<int>(nums.begin(), nums.end()).size() ==
               nums.size();
  }
};
