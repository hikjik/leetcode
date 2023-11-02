#pragma once

#include <cmath>
#include <vector>

// Time:
// Space:

class Solution {
public:
  static int
  minTimeToVisitAllPoints(const std::vector<std::vector<int>> &points) {
    int ans = 0;
    for (int i = 1; i < std::ssize(points); ++i) {
      ans += std::max(std::abs(points[i][0] - points[i - 1][0]),
                      std::abs(points[i][1] - points[i - 1][1]));
    }
    return ans;
  }
};
