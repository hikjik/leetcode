#pragma once

#include <vector>

class Solution {
public:
  static std::vector<std::vector<int>>
  flipAndInvertImage(const std::vector<std::vector<int>> &image) {
    const int n = image.size(), m = image.back().size();

    std::vector ans(n, std::vector<int>(m));
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < (m + 1) / 2; ++j) {
        ans[i][j] = image[i][m - j - 1] ^ 1;
        ans[i][m - j - 1] = image[i][j] ^ 1;
      }
    }
    return ans;
  }
};
