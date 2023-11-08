#pragma once

// Time: O(1)
// Space: O(1)

#include <cmath>

class Solution {
public:
  static bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
    const auto min_time = std::max(std::abs(sx - fx), std::abs(sy - fy));
    if (min_time == 0 && t == 1) {
      return false;
    }
    return min_time <= t;
  }
};
