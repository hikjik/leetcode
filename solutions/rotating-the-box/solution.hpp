#pragma once

#include <vector>

// Time: O(NM)
// Space: O(1)

class Solution {
public:
  static std::vector<std::vector<char>>
  rotateTheBox(const std::vector<std::vector<char>> &box) {
    const int m = box.size(), n = box.back().size();
    std::vector ans(n, std::vector<char>(m, '.'));
    for (int i = m - 1; i >= 0; --i) {
      for (int k = n - 1, j = n - 1; j >= 0; --j) {
        if (box[i][j] == '#') {
          ans[k--][m - i - 1] = '#';
        } else if (box[i][j] == '*') {
          ans[j][m - i - 1] = '*';
          k = j - 1;
        }
      }
    }
    return ans;
  }
};
