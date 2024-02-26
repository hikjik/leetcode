#pragma once

#include <tuple>
#include <vector>

// Time: O(N^2)
// Space: O(1)

class Solution {
public:
  static long long
  largestSquareArea(const std::vector<std::vector<int>> &bottomLeft,
                    const std::vector<std::vector<int>> &topRight) {
    const int n = bottomLeft.size();
    int side = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
        const auto dx = std::min(topRight[i][0], topRight[j][0]) -
                        std::max(bottomLeft[i][0], bottomLeft[j][0]);
        const auto dy = std::min(topRight[i][1], topRight[j][1]) -
                        std::max(bottomLeft[i][1], bottomLeft[j][1]);
        if (dx > 0 && dy > 0) {
          side = std::max(side, std::min(dx, dy));
        }
      }
    }
    return static_cast<long long>(side) * side;
  }
};
