#pragma once

#include <vector>

class Solution {
private:
  static const int kMod = 1e9 + 7;

public:
  static int numMusicPlaylists(int n, int goal, int k) {
    std::vector dp(goal + 1, std::vector<long long>(n + 1));
    dp[0][0] = 1;

    for (int i = 1; i <= goal; ++i) {
      for (int j = 1; j <= n; ++j) {
        dp[i][j] = (dp[i - 1][j - 1] * (n - j + 1) +
                    dp[i - 1][j] * std::max(0, j - k)) %
                   kMod;
      }
    }

    return dp[goal][n];
  }
};
