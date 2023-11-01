#pragma once

#include <vector>

/*
  661. Image Smoother
  https://leetcode.com/problems/image-smoother/
  Difficulty: Easy
  Tags: Array, Matrix
  Time:
  Space:
*/

class Solution {
public:
  static std::vector<std::vector<int>>
  imageSmoother(const std::vector<std::vector<int>> &img) {
    const int m = img.size(), n = img.back().size();
    std::vector ans(m, std::vector<int>(n));
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        int sum = 0, cnt = 0;
        for (int x = std::max(0, i - 1); x < std::min(m, i + 2); ++x) {
          for (int y = std::max(0, j - 1); y < std::min(n, j + 2); ++y) {
            sum += img[x][y], ++cnt;
          }
        }
        ans[i][j] = sum / cnt;
      }
    }
    return ans;
  }
};
