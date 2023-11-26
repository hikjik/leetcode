#pragma once

#include <limits>
#include <ranges>
#include <vector>

// Time: O(NlogN)
// Space: O(N)

class Solution {
public:
  static std::vector<int>
  lexicographicallySmallestArray(const std::vector<int> &nums, int limit) {
    std::vector<int> indexes(nums.size());
    std::iota(indexes.begin(), indexes.end(), 0);
    std::ranges::sort(indexes, [&](int i, int j) { return nums[i] < nums[j]; });

    std::vector<std::vector<int>> groups;
    for (int i = 0; i < std::ssize(indexes); ++i) {
      if (!i || nums[indexes[i]] - nums[indexes[i - 1]] > limit) {
        groups.emplace_back();
      }
      groups.back().push_back(indexes[i]);
    }

    std::vector<int> ans(nums.size());
    for (const auto &group : groups) {
      auto sorted = group;
      std::ranges::sort(sorted);

      for (int i = 0; i < std::ssize(sorted); ++i) {
        ans[sorted[i]] = nums[group[i]];
      }
    }
    return ans;
  }
};
