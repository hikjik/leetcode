#pragma once

#include <vector>

// Time: O(NM)
// Space: O(1)

class Solution {
public:
  static std::vector<std::vector<int>>
  findFarmland(const std::vector<std::vector<int>> &land) {
    const int m = land.size(), n = land.back().size();
    std::vector<std::vector<int>> ans;
    for (int r1 = 0; r1 < m; ++r1) {
      for (int c1 = 0; c1 < n; ++c1) {
        if (land[r1][c1] && (!r1 || !land[r1 - 1][c1]) &&
            (!c1 || !land[r1][c1 - 1])) {
          int r2 = r1;
          while (r2 + 1 < m && land[r2 + 1][c1]) {
            ++r2;
          }
          int c2 = c1;
          while (c2 + 1 < n && land[r1][c2 + 1]) {
            ++c2;
          }
          ans.push_back({r1, c1, r2, c2});
        }
      }
    }
    return ans;
  }
};
