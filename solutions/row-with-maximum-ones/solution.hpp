#pragma once

#include <algorithm>
#include <numeric>
#include <vector>

// Time:
// Space:

class Solution {
public:
  static std::vector<int>
  rowAndMaximumOnes(const std::vector<std::vector<int>> &mat) {
    std::vector<int> ones(mat.size());
    std::transform(mat.begin(), mat.end(), ones.begin(), [](const auto &row) {
      return std::count(row.begin(), row.end(), 1);
    });
    const auto it = std::max_element(ones.begin(), ones.end());
    const int index = it - ones.begin();
    return {index, *it};
  }
};
