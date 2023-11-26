#pragma once

#include <algorithm>
#include <vector>

// Time: O(MN)
// Space: O(1)

namespace stl {

// Time: O(MN)
// Space: O(MN)
class Solution {
public:
  static bool areSimilar(const std::vector<std::vector<int>> &mat, int k) {
    k %= mat.back().size();
    auto copy = mat;
    for (int i = 0; auto &row : copy) {
      if (i++ & 1) {
        std::rotate(row.rbegin(), row.rbegin() + k, row.rend());
      } else {
        std::rotate(row.begin(), row.begin() + k, row.end());
      }
    }
    return copy == mat;
  }
};

} // namespace stl

namespace space {

// Time: O(MN)
// Space: O(1)
class Solution {
public:
  static bool areSimilar(const std::vector<std::vector<int>> &mat, int k) {
    const int n = mat.back().size();
    k %= n;
    for (int i = 0; const auto &row : mat) {
      if (!areSimilar(row, i++ & 1 ? k : n - k)) {
        return false;
      }
    }
    return true;
  }

private:
  static bool areSimilar(const std::vector<int> &row, int k) {
    const int n = row.size();
    for (int i = 0; i < n; ++i) {
      if (row[i] != row[(i + k) % n]) {
        return false;
      }
    }
    return true;
  }
};

} // namespace space
