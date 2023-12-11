#pragma once

#include <ranges>
#include <vector>

// Time: O(NM)
// Space: O(N)

namespace dp {

// Time: O(NM)
// Space: O(NM)
class Solution {
public:
  static int countPyramids(std::vector<std::vector<int>> grid) {
    auto ans = countPyramidalPlot(grid);
    std::ranges::reverse(grid);
    return ans + countPyramidalPlot(grid);
  }

private:
  static int countPyramidalPlot(std::vector<std::vector<int>> dp) {
    const int m = dp.size(), n = dp.back().size();
    int ans = 0;
    for (int i = m - 2; i >= 0; --i) {
      for (int j = 1; j < n - 1; ++j) {
        if (dp[i][j]) {
          dp[i][j] += std::min({
              dp[i + 1][j - 1],
              dp[i + 1][j],
              dp[i + 1][j + 1],
          });
          ans += dp[i][j] - 1;
        }
      }
    }
    return ans;
  }
};

} // namespace dp

namespace optimized {

// Time: O(NM)
// Space: O(N)
class Solution {
public:
  static int countPyramids(const std::vector<std::vector<int>> &grid) {
    return countPyramids(grid.cbegin(), grid.cend()) +
           countPyramids(grid.crbegin(), grid.crend());
  }

private:
  template <typename Iterator>
  static int countPyramids(Iterator first, Iterator last) {
    const int n = first->size();
    std::vector<int> dp(n + 1);
    int ans = 0;
    for (auto it = first; it != last; ++it) {
      const auto &row = *it;
      for (int prev = 0, j = 0; j < n; ++j) {
        std::swap(prev, dp[j]);
        if (row[j]) {
          dp[j] = 1 + std::min({prev, dp[j], dp[j + 1]});
          ans += dp[j] - 1;
        } else {
          dp[j] = 0;
        }
      }
    }
    return ans;
  }
};

} // namespace optimized
