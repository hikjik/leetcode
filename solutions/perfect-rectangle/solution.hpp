#pragma once

#include <cmath>
#include <ranges>
#include <unordered_map>
#include <vector>

// Time: O(N)
// Space: O(N)

class Solution {
public:
  static constexpr long long kSize = 2e5 + 1;

  static bool
  isRectangleCover(const std::vector<std::vector<int>> &rectangles) {
    std::unordered_map<long long, int> map;
    for (const auto &r : rectangles) {
      ++map[r[0] * kSize + r[1]];
      --map[r[0] * kSize + r[3]];
      --map[r[2] * kSize + r[1]];
      ++map[r[2] * kSize + r[3]];
    }
    std::erase_if(map, [](const auto &p) { return !p.second; });
    if (map.size() != 4) {
      return false;
    }
    return std::ranges::all_of(
        map, [](const auto &p) { return std::abs(p.second) == 1; });
  }
};
