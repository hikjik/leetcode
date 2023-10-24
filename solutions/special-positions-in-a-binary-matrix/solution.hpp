#pragma once

#include <vector>

class Solution {
public:
  static int numSpecial(const std::vector<std::vector<int>> &mat) {
    const int m = mat.size(), n = mat.back().size();
    std::vector<int> rows(m), cols(n);

    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (mat[i][j]) {
          ++rows[i], ++cols[j];
        }
      }
    }

    int ans = 0;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (mat[i][j] && rows[i] == 1 && cols[j] == 1) {
          ++ans;
        }
      }
    }
    return ans;
  }
};
