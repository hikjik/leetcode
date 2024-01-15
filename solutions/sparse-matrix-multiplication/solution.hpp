#pragma once

#include <vector>

// Time: O(NMK)
// Space: O(MK+KN)

namespace naive {

// Time: O(NMK)
// Space: O(1)
class Solution {
public:
  static std::vector<std::vector<int>>
  multiply(const std::vector<std::vector<int>> &mat1,
           const std::vector<std::vector<int>> &mat2) {
    const int m = mat1.size(), k = mat2.size(), n = mat2.back().size();
    std::vector ans(m, std::vector<int>(n));
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        for (int l = 0; l < k; ++l) {
          ans[i][j] += mat1[i][l] * mat2[l][j];
        }
      }
    }
    return ans;
  }
};

} // namespace naive

namespace opt {

// Time: O(NMK)
// Space: O(MK+KN)
class Solution {
public:
  static std::vector<std::vector<int>>
  multiply(const std::vector<std::vector<int>> &mat1,
           const std::vector<std::vector<int>> &mat2) {
    const int m = mat1.size(), n = mat2.back().size();
    const auto c1 = compress(mat1), c2 = compress(mat2);
    std::vector ans(m, std::vector<int>(n));
    for (int i = 0; i < m; ++i) {
      for (const auto &[v1, k] : c1[i]) {
        for (const auto &[v2, j] : c2[k]) {
          ans[i][j] += v1 * v2;
        }
      }
    }
    return ans;
  }

private:
  static std::vector<std::vector<std::pair<int, int>>>
  compress(const std::vector<std::vector<int>> &mat) {
    std::vector<std::vector<std::pair<int, int>>> ans(mat.size());
    for (int i = 0; i < std::ssize(mat); ++i) {
      for (int j = 0; j < std::ssize(mat[i]); ++j) {
        if (mat[i][j]) {
          ans[i].push_back({mat[i][j], j});
        }
      }
    }
    return ans;
  }
};

} // namespace opt
