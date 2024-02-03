#pragma once

#include <vector>

// Time: O(N^3)
// Space: O(1)

class Solution {
public:
  static int numberOfPairs(const std::vector<std::vector<int>> &points) {
    const int n = points.size();
    int ans = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (i == j || points[i][0] > points[j][0] ||
            points[i][1] < points[j][1]) {
          continue;
        }
        bool ok = true;
        for (int k = 0; k < n; ++k) {
          if (k == j || k == i) {
            continue;
          }
          if (points[i][0] <= points[k][0] && points[k][0] <= points[j][0] &&
              points[j][1] <= points[k][1] && points[k][1] <= points[i][1]) {
            ok = false;
            break;
          }
        }
        ans += ok;
      }
    }
    return ans;
  }
};
