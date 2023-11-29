#pragma once

#include <ranges>
#include <vector>

// Time: O(MlogM)
// Space: O(MN)

class Solution {
public:
  static std::vector<std::vector<int>>
  sortTheStudents(std::vector<std::vector<int>> score, int k) {
    std::ranges::sort(
        score, [k](const auto &r1, const auto &r2) { return r1[k] > r2[k]; });
    return score;
  }
};
