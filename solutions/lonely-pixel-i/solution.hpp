#pragma once

#include <vector>

// Time: O(MN)
// Space: O(M+N)

class Solution {
public:
  static int findLonelyPixel(const std::vector<std::vector<char>> &picture) {
    const int m = picture.size(), n = picture.back().size();
    std::vector<int> rows(m), cols(n);
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (picture[i][j] == 'B') {
          ++rows[i], ++cols[j];
        }
      }
    }

    int ans = 0;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (picture[i][j] == 'B' && rows[i] == 1 && cols[j] == 1) {
          ++ans;
        }
      }
    }
    return ans;
  }
};
