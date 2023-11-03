#pragma once

#include <algorithm>
#include <array>

// Time:
// Space:

class Solution {
private:
  static const size_t kMaxRows = 101;

public:
  static double champagneTower(int poured, int query_row, int query_glass) {
    std::array<double, kMaxRows> dp{};
    dp[0] = poured;

    for (int i = 0; i < query_row; ++i) {
      for (int j = i; j >= 0; --j) {
        const auto amount = (dp[j] - 1.0) / 2.0;
        dp[j] = 0;
        if (amount > 0.0) {
          dp[j] += amount;
          dp[j + 1] += amount;
        }
      }
    }
    return std::min(dp[query_glass], 1.0);
  }
};
