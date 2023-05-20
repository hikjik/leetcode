#pragma once

#include <algorithm>
#include <vector>

class Solution {
public:
  static int findMinArrowShots(std::vector<std::vector<int>> points) {
    const int n = points.size();
    std::sort(points.begin(), points.end(),
              [](const auto &lhs, const auto &rhs) { return lhs[1] < rhs[1]; });

    int cnt = 1;
    for (int i = 1, r = points[0][1]; i < n; ++i) {
      if (points[i][0] > r) {
        r = points[i][1];
        cnt++;
      }
    }
    return cnt;
  }
};
