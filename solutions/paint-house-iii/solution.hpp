#pragma once

#include <functional>
#include <vector>

// Time: O(MTN^2)
// Space: O(TN)

namespace memo {

// Time: O(MTN^2)
// Space: O(MTN)
class Solution {
public:
  static constexpr int kMaxCost = 0x3f3f3f3f;

  static int minCost(const std::vector<int> &houses,
                     const std::vector<std::vector<int>> &cost, int m, int n,
                     int target) {
    std::vector dp(m, std::vector(target + 1, std::vector<int>(n + 1, -1)));

    std::function<int(int, int, int)> minCost = [&](int i, int t, int c) {
      if (i == m) {
        return t == target ? 0 : kMaxCost;
      }
      if (t > target) {
        return kMaxCost;
      }
      if (dp[i][t][c] != -1) {
        return dp[i][t][c];
      }
      dp[i][t][c] = kMaxCost;
      if (houses[i]) {
        dp[i][t][c] = minCost(i + 1, t + (houses[i] != c), houses[i]);
      } else {
        for (int j = 1; j <= n; ++j) {
          dp[i][t][c] = std::min(
              dp[i][t][c], cost[i][j - 1] + minCost(i + 1, t + (j != c), j));
        }
      }
      return dp[i][t][c];
    };

    return minCost(0, 0, 0) == kMaxCost ? -1 : dp[0][0][0];
  }
};

} // namespace memo

namespace dp {

// Time: O(MTN^2)
// Space: O(MTN)
class Solution {
public:
  static constexpr int kMaxCost = 0x3f3f3f3f;

  static int minCost(const std::vector<int> &houses,
                     const std::vector<std::vector<int>> &cost, int m, int n,
                     int target) {
    std::vector dp(m, std::vector(target + 1, std::vector<int>(n, kMaxCost)));
    for (int c = 1; c <= n; ++c) {
      if (houses[0] == c) {
        dp[0][1][c - 1] = 0;
      } else if (!houses[0]) {
        dp[0][1][c - 1] = cost[0][c - 1];
      }
    }

    for (int i = 1; i < m; ++i) {
      for (int t = 1; t <= target && t <= i + 1; ++t) {
        for (int c = 1; c <= n; ++c) {
          if (houses[i] && c != houses[i]) {
            continue;
          }
          const auto paintCost = houses[i] ? 0 : cost[i][c - 1];
          for (int j = 1; j <= n; ++j) {
            dp[i][t][c - 1] = std::min(
                dp[i][t][c - 1], paintCost + dp[i - 1][t - (j != c)][j - 1]);
          }
        }
      }
    }

    const auto ans = std::ranges::min(dp[m - 1][target]);
    return ans == kMaxCost ? -1 : ans;
  }
};

} // namespace dp

namespace opt {

// Time: O(MTN^2)
// Space: O(TN)
class Solution {
public:
  static constexpr int kMaxCost = 0x3f3f3f3f;

  static int minCost(const std::vector<int> &houses,
                     const std::vector<std::vector<int>> &cost, int m, int n,
                     int target) {
    std::vector dp(2, std::vector(target + 1, std::vector<int>(n, kMaxCost)));
    for (int c = 1; c <= n; ++c) {
      if (houses[0] == c) {
        dp[0][1][c - 1] = 0;
      } else if (!houses[0]) {
        dp[0][1][c - 1] = cost[0][c - 1];
      }
    }

    for (int i = 1; i < m; ++i) {
      for (int t = 1; t <= target && t <= i + 1; ++t) {
        for (int c = 1; c <= n; ++c) {
          dp[1][t][c - 1] = kMaxCost;
          if (houses[i] && c != houses[i]) {
            continue;
          }
          const auto paintCost = houses[i] ? 0 : cost[i][c - 1];
          for (int j = 1; j <= n; ++j) {
            dp[1][t][c - 1] = std::min(dp[1][t][c - 1],
                                       paintCost + dp[0][t - (j != c)][j - 1]);
          }
        }
      }
      std::swap(dp[0], dp[1]);
    }

    const auto ans = std::ranges::min(dp[0][target]);
    return ans == kMaxCost ? -1 : ans;
  }
};

} // namespace opt
