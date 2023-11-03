#pragma once

#include <vector>

// Time:
// Space:

class Solution {
public:
  static bool
  checkStraightLine(const std::vector<std::vector<int>> &coordinates) {
    const auto x0 = coordinates[0][0];
    const auto x1 = coordinates[1][0];
    const auto y0 = coordinates[0][1];
    const auto y1 = coordinates[1][1];
    const auto dx = x1 - x0;
    const auto dy = y1 - y0;

    for (const auto &xy : coordinates) {
      if ((xy[0] - x0) * dy != dx * (xy[1] - y0)) {
        return false;
      }
    }
    return true;
  }
};
