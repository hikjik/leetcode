#pragma once

#include <ranges>
#include <unordered_map>
#include <vector>

// Time: O(N)
// Space: O(N)

class Solution {
public:
  static bool isPossibleToSplit(const std::vector<int> &nums) {
    std::unordered_map<int, int> cnt;
    for (auto num : nums) {
      ++cnt[num];
    }
    return std::ranges::all_of(cnt, [](const auto &p) { return p.second < 3; });
  }
};
