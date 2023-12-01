#pragma once

#include <vector>

// Time: O(MN)
// Space: O(N+M)

class Solution {
public:
  static std::vector<std::vector<int>> restoreMatrix(std::vector<int> rowSum,
                                                     std::vector<int> colSum) {
    const int m = rowSum.size(), n = colSum.size();
    std::vector ans(m, std::vector<int>(n));
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        ans[i][j] = std::min(rowSum[i], colSum[j]);
        rowSum[i] -= ans[i][j];
        colSum[j] -= ans[i][j];
      }
    }
    return ans;
  }
};
