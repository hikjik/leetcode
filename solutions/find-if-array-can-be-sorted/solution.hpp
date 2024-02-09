#pragma once

#include <bit>
#include <ranges>
#include <vector>

// Time: O(NlogN)
// Space: O(N)

class Solution {
public:
  static bool canSortArray(std::vector<int> nums) {
    for (auto first = nums.begin(); first != nums.end();) {
      auto last = std::ranges::adjacent_find(
          first, nums.end(), [](unsigned a, unsigned b) {
            return std::popcount(a) != std::popcount(b);
          });
      if (last != nums.end()) {
        last = std::next(last);
      }
      std::ranges::sort(first, last);
      first = last;
    }
    return std::ranges::is_sorted(nums);
  }
};
