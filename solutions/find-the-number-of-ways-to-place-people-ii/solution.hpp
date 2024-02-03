#pragma once

#include <climits>
#include <ranges>
#include <vector>

// Time: O(N^2)
// Space: O(N)

class Solution {
public:
  static int numberOfPairs(std::vector<std::vector<int>> points) {
    std::ranges::sort(points, [](auto &lhs, auto &rhs) {
      return std::tie(lhs[1], rhs[0]) > std::tie(rhs[1], lhs[0]);
    });

    int ans = 0;
    for (size_t i = 0; i < points.size(); ++i) {
      auto minx = INT_MAX;
      for (size_t j = i + 1; j < points.size(); ++j) {
        if (points[j][0] >= points[i][0] && points[j][0] < minx) {
          ++ans;
          minx = std::min(minx, points[j][0]);
        }
      }
    }
    return ans;
  }
};
