#pragma once

#include <array>
#include <string>
#include <vector>

// Time: O(N!)
// Space: O(N)
// Notes: [Eight queens puzzle](https://w.wiki/84eA)

class Solution {
public:
  static constexpr size_t kSize = 9;

  std::array<bool, kSize> cols{};
  std::array<bool, kSize * 2 - 1> diag1{};
  std::array<bool, kSize * 2 - 1> diag2{};

  int totalNQueens(int n) {
    int total = 0;
    totalNQueens(0, n, total);
    return total;
  }

  void totalNQueens(int r, int n, int &total) {
    if (r == n) {
      total++;
      return;
    }

    for (int c = 0; c < n; ++c) {
      if (!cols[c] && !diag1[r + c] && !diag2[r + n - c - 1]) {
        cols[c] = diag1[r + c] = diag2[r + n - c - 1] = true;
        totalNQueens(r + 1, n, total);
        cols[c] = diag1[r + c] = diag2[r + n - c - 1] = false;
      }
    }
  }
};
