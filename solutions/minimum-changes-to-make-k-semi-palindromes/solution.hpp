#pragma once

#include <cstring>
#include <ranges>
#include <string>
#include <vector>

// Time: O(N^3)
// Space: O(N^2)

class Solution {
public:
  static int minimumChanges(std::string s, int k) {
    const int n = s.size();

    std::vector cost(n + 1, std::vector<int>(n + 1, n));
    std::vector costD(n + 1, std::vector<int>(n + 1));
    for (int d = 1; d <= n / 2; ++d) {
      for (auto &r : costD) {
        std::ranges::fill(r, 0);
      }
      for (int l = 2 * d; l <= n; l += d) {
        for (int i = 0; i + l <= n; ++i) {
          int ops = 0;
          for (int k = 0; k < d; ++k) {
            ops += s[i + k] != s[i + l - d + k];
          }
          costD[i][l] = ops + costD[i + d][l - 2 * d];
          cost[i][l] = std::min(cost[i][l], costD[i][l]);
        }
      }
    }

    std::vector dp(n + 1, std::vector<int>(k + 1, n));
    dp[n][0] = 0;
    for (int t = 1; t <= k; ++t) {
      for (int i = n - 1; i >= 0; --i) {
        for (int l = 2; l <= n - i - 2 * (t - 1); ++l) {
          dp[i][t] = std::min(dp[i][t], cost[i][l] + dp[i + l][t - 1]);
        }
      }
    }
    return dp[0][k];
  }
};
