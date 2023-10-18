#pragma once

#include <algorithm>
#include <vector>

class Solution {
public:
  static int deleteGreatestValue(std::vector<std::vector<int>> grid) {
    for (auto &row : grid) {
      std::sort(row.begin(), row.end());
    }
    int sum = 0;
    for (size_t j = 0; j < grid.back().size(); ++j) {
      const auto it = std::max_element(
          grid.begin(), grid.end(),
          [j](const auto &lhs, const auto &rhs) { return lhs[j] < rhs[j]; });
      sum += (*it)[j];
    }
    return sum;
  }
};
