#pragma once

#include <ranges>
#include <unordered_map>
#include <vector>

// K = min(M, N)
// Time: O(MNlogK)
// Space: O(K)

namespace hash_table {

// Time: O(MNlogK)
// Space: O(MN)
class Solution {
public:
  static std::vector<std::vector<int>>
  diagonalSort(std::vector<std::vector<int>> mat) {
    const int m = mat.size(), n = mat.back().size();
    std::unordered_map<int, std::vector<int>> groups;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        groups[i - j].push_back(mat[i][j]);
      }
    }
    for (auto &[_, group] : groups) {
      std::ranges::sort(group);
    }
    for (int i = m - 1; i >= 0; --i) {
      for (int j = n - 1; j >= 0; --j) {
        mat[i][j] = groups[i - j].back();
        groups[i - j].pop_back();
      }
    }
    return mat;
  }
};

} // namespace hash_table

namespace optimized {

// Time: O(MNlogK)
// Space: O(K)
class Solution {
public:
  static std::vector<std::vector<int>>
  diagonalSort(std::vector<std::vector<int>> mat) {
    const int m = mat.size(), n = mat.back().size();
    for (int d = m - 1; d >= 1 - n; --d) {
      std::vector<int> group;
      for (int i = std::max(0, d); i < m && i - d < n; ++i) {
        group.push_back(mat[i][i - d]);
      }
      std::ranges::sort(group);
      for (int i = std::max(0, d), k = 0; i < m && i - d < n; ++i) {
        mat[i][i - d] = group[k++];
      }
    }
    return mat;
  }
};

} // namespace optimized
