#pragma once

#include <ranges>
#include <vector>

// Time: O(N^2)
// Space: O(1)

class Solution {
public:
  static int findChampion(const std::vector<std::vector<int>> &grid) {
    return std::distance(grid.begin(),
                         std::ranges::find_if(grid, [](const auto &row) {
                           return std::ranges::count(row, 0) == 1;
                         }));
  }
};
