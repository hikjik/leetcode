#pragma once

#include <cmath>
#include <vector>

class Solution {
public:
  static std::vector<int>
  findColumnWidth(const std::vector<std::vector<int>> &grid) {
    std::vector<int> ans(grid.back().size());
    for (const auto &row : grid) {
      for (size_t j = 0; j < row.size(); ++j) {
        ans[j] = std::max(ans[j], width(row[j]));
      }
    }
    return ans;
  }

private:
  static int width(int num) {
    return num ? std::log10(std::abs(num)) + 1 + (num < 0) : 1;
  }
};
