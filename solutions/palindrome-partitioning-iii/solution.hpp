#pragma once

#include <climits>
#include <string>
#include <vector>

// Time: O(N^3)
// Space: O(N^2)

namespace memo {

// Time: O(N^3)
// Space: O(N^2)
class Solution {
public:
  static int palindromePartition(std::string s, int k) {
    const int n = s.size();
    std::vector cost(n, std::vector<char>(n));
    for (int d = 1; d < n; ++d) {
      for (int i = 0; i + d < n; ++i) {
        cost[i][i + d] = (s[i] != s[i + d]) + cost[i + 1][i + d - 1];
      }
    }
    std::vector memo(n + 1, std::vector<int>(k + 1, n));
    return palindromePartition(n, k, cost, &memo);
  }

private:
  static int palindromePartition(int i, int t,
                                 const std::vector<std::vector<char>> &cost,
                                 std::vector<std::vector<int>> *memo) {
    if (t == 1) {
      return cost[0][i - 1];
    }
    auto &ans = (*memo)[i][t];
    if (ans >= i) {
      for (int j = t - 1; j < i; ++j) {
        ans = std::min(ans, cost[j][i - 1] +
                                palindromePartition(j, t - 1, cost, memo));
      }
    }
    return ans;
  }
};

} // namespace memo

namespace dp {

// Time: O(N^3)
// Space: O(N^2)
class Solution {
public:
  static int palindromePartition(std::string s, int k) {
    const int n = s.size();
    std::vector cost(n, std::vector<char>(n));
    for (int d = 1; d < n; ++d) {
      for (int i = 0; i + d < n; ++i) {
        cost[i][i + d] = (s[i] != s[i + d]) + cost[i + 1][i + d - 1];
      }
    }

    std::vector dp(n + 1, std::vector<int>(k + 1, n));
    for (int i = 1; i <= n; ++i) {
      dp[i][1] = cost[0][i - 1];
    }
    for (int t = 2; t <= k; ++t) {
      for (int i = t; i <= n; ++i) {
        for (int j = t - 1; j < i; ++j) {
          dp[i][t] = std::min(dp[i][t], cost[j][i - 1] + dp[j][t - 1]);
        }
      }
    }
    return dp[n][k];
  }
};

} // namespace dp
