#pragma once

#include <climits>
#include <ranges>
#include <unordered_map>
#include <vector>

// Time: O(MN)
// Space: O(M)

namespace ht {

// Time: O(MN)
// Space: O(MN)
class Solution {
public:
  static int smallestCommonElement(const std::vector<std::vector<int>> &mat) {
    const int m = mat.size(), n = mat.back().size();
    std::unordered_map<int, int> counter;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        ++counter[mat[i][j]];
      }
    }
    int ans = INT_MAX;
    for (const auto &[num, cnt] : counter) {
      if (cnt == m) {
        ans = std::min(ans, num);
      }
    }
    return ans == INT_MAX ? -1 : ans;
  }
};

} // namespace ht

namespace bs {

// Time: O(MNlogN)
// Space: O(1)
class Solution {
public:
  static int smallestCommonElement(const std::vector<std::vector<int>> &mat) {
    int ans = INT_MAX;
    for (auto num : mat[0]) {
      if (std::ranges::all_of(mat, [=](const auto &row) {
            return std::ranges::binary_search(row, num);
          })) {
        ans = std::min(ans, num);
      }
    }
    return ans == INT_MAX ? -1 : ans;
  }
};

} // namespace bs

namespace rp {

// Time: O(MN)
// Space: O(M)
class Solution {
public:
  static int smallestCommonElement(const std::vector<std::vector<int>> &mat) {
    const int m = mat.size(), n = mat.back().size();
    int max = 0, cnt = 0;
    std::vector<int> cols(m);
    for (int k = 0; k < n; ++k) {
      for (int i = 0; i < m; ++i) {
        while (cols[i] < n && mat[i][cols[i]] < max) {
          ++cols[i];
        }
        if (cols[i] == n) {
          return -1;
        }
        if (mat[i][cols[i]] == max && ++cnt == m) {
          return max;
        } else if (mat[i][cols[i]] > max) {
          max = mat[i][cols[i]];
          cnt = 1;
        }
      }
    }
    throw;
  }
};

} // namespace rp
