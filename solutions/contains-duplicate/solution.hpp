#pragma once

#include <ranges>
#include <unordered_set>
#include <vector>

// Time: O(N)
// Space: O(N)

class Solution {
public:
  static bool containsDuplicate(const std::vector<int> &nums) {
    std::unordered_set<int> set;
    return std::ranges::any_of(nums,
                               [&](int a) { return !set.insert(a).second; });
  }
};
