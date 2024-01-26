#pragma once

#include <functional>
#include <vector>

// K = maxMove
// Time: O(NMK)
// Space: O(NM)

namespace memo {

// Time: O(NMK)
// Space: O(NMK)
class Solution {
public:
  static constexpr int kMod = 1e9 + 7;

  static int findPaths(int m, int n, int maxMove, int startRow,
                       int startColumn) {
    std::vector memo(m, std::vector(n, std::vector<int>(maxMove + 1, -1)));

    std::function<int(int, int, int)> findPath = [&](int i, int j, int s) {
      if (i < 0 || j < 0 || i >= m || j >= n) {
        return 1;
      }
      if (s == 0) {
        return 0;
      }
      auto &ans = memo[i][j][s];
      if (ans == -1) {
        ans = (0LL + findPath(i + 1, j, s - 1) + findPath(i - 1, j, s - 1) +
               findPath(i, j + 1, s - 1) + findPath(i, j - 1, s - 1)) %
              kMod;
      }
      return ans;
    };

    return findPath(startRow, startColumn, maxMove);
  }
};

} // namespace memo

namespace dp {

// Time: O(NMK)
// Space: O(NM)
class Solution {
public:
  static constexpr int kMod = 1e9 + 7;

  static int findPaths(int m, int n, int maxMove, int startRow,
                       int startColumn) {
    std::vector dp(2, std::vector(m, std::vector<int>(n)));
    dp[0][startRow][startColumn] = 1;

    long long ans = 0;
    for (int s = 1; s <= maxMove; ++s) {
      for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
          ans += i == 0 ? dp[0][i][j] : 0;
          ans += j == 0 ? dp[0][i][j] : 0;
          ans += i == m - 1 ? dp[0][i][j] : 0;
          ans += j == n - 1 ? dp[0][i][j] : 0;
          ans %= kMod;

          long long tmp = 0;
          tmp += i > 0 ? dp[0][i - 1][j] : 0;
          tmp += j > 0 ? dp[0][i][j - 1] : 0;
          tmp += i < m - 1 ? dp[0][i + 1][j] : 0;
          tmp += j < n - 1 ? dp[0][i][j + 1] : 0;
          dp[1][i][j] = tmp % kMod;
        }
      }
      dp[0].swap(dp[1]);
    }
    return ans;
  }
};

} // namespace dp
