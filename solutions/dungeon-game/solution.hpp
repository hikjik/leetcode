#pragma once

#include <climits>
#include <vector>

// Time: O(NM)
// Space: O(N)

namespace memo {

// Time: O(NM)
// Space: O(NM)
class Solution {
public:
  static int calculateMinimumHP(const std::vector<std::vector<int>> &dungeon) {
    const int m = dungeon.size(), n = dungeon.back().size();
    std::vector memo(m, std::vector<int>(n, -1));
    return 1 + calculateMinimumHP(0, 0, dungeon, &memo);
  }

  static int calculateMinimumHP(int i, int j,
                                const std::vector<std::vector<int>> &dungeon,
                                std::vector<std::vector<int>> *memo) {
    const int m = dungeon.size(), n = dungeon.back().size();
    if (i == m && j == n - 1) {
      return 0;
    }
    if (i == m || j == n) {
      return INT_MAX;
    }
    auto &hp = (*memo)[i][j];
    if (hp == -1) {
      hp = std::max(0, std::min(calculateMinimumHP(i + 1, j, dungeon, memo),
                                calculateMinimumHP(i, j + 1, dungeon, memo)) -
                           dungeon[i][j]);
    }
    return hp;
  }
};

} // namespace memo

namespace dp {

// Time: O(NM)
// Space: O(NM)
class Solution {
public:
  static int calculateMinimumHP(const std::vector<std::vector<int>> &dungeon) {
    const int m = dungeon.size(), n = dungeon.back().size();
    std::vector dp(m + 1, std::vector<int>(n + 1, INT_MAX));
    dp[m][n - 1] = 0;
    for (int i = m - 1; i >= 0; --i) {
      for (int j = n - 1; j >= 0; --j) {
        dp[i][j] =
            std::max(std::min(dp[i + 1][j], dp[i][j + 1]) - dungeon[i][j], 0);
      }
    }
    return dp[0][0] + 1;
  }
};

} // namespace dp

namespace optimized {

// Time: O(NM)
// Space: O(N)
class Solution {
public:
  static int calculateMinimumHP(const std::vector<std::vector<int>> &dungeon) {
    const int m = dungeon.size(), n = dungeon.back().size();
    std::vector<int> dp(n + 1, INT_MAX);
    dp[n - 1] = 0;
    for (int i = m - 1; i >= 0; --i) {
      for (int j = n - 1; j >= 0; --j) {
        dp[j] = std::max(std::min(dp[j], dp[j + 1]) - dungeon[i][j], 0);
      }
    }
    return 1 + dp[0];
  }
};

} // namespace optimized
