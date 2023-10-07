#pragma once

#include <array>

class Solution {
private:
  static const int kMod = 1e9 + 7;

public:
  static int numOfArrays(int n, int m, int k) {
    std::array<std::array<std::array<int, 51>, 101>, 51> dp{};
    for (int max = 0; max <= m; ++max) {
      dp[n][max][0] = 1;
    }

    for (int i = n - 1; i >= 0; --i) {
      for (int r = 0; r <= k; ++r) {
        auto sum = 0LL;
        for (int max = m; max >= 0; --max) {
          auto cnt = 1LL * max * dp[i + 1][max][r];
          if (r) {
            cnt += sum;
            sum += dp[i + 1][max][r - 1];
          }
          dp[i][max][r] = cnt % kMod;
        }
      }
    }

    return dp[0][0][k];
  }
};
