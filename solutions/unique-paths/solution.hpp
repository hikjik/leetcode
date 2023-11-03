#pragma once

#include <numeric>
#include <vector>

// Time: O(min(N, M))
// Space: O(1)

namespace memo {

// Time: O(NM)
// Space: O(NM)
class Solution {
public:
  static int uniquePaths(int m, int n) {
    std::vector memo(m, std::vector<int>(n, 0));
    return uniquePaths(m - 1, n - 1, &memo);
  }

private:
  static int uniquePaths(int m, int n, std::vector<std::vector<int>> *memo) {
    if (!n || !m) {
      return 1;
    }
    auto &cnt = (*memo)[m][n];
    if (!cnt) {
      cnt = uniquePaths(m - 1, n, memo) + uniquePaths(m, n - 1, memo);
    }
    return cnt;
  }
};

} // namespace memo

namespace dp {

// Time: O(NM)
// Space: O(NM)
class Solution {
public:
  static int uniquePaths(int m, int n) {
    std::vector dp(m, std::vector<int>(n, 1));
    for (int i = 1; i < m; ++i) {
      for (int j = 1; j < n; ++j) {
        dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
      }
    }
    return dp[m - 1][n - 1];
  }
};

} // namespace dp

namespace optimized {

// Time: O(NM)
// Space: O(min(N, M))
class Solution {
public:
  static int uniquePaths(int m, int n) {
    std::vector<int> dp(std::min(n, m), 1);
    for (int i = 1; i < std::max(n, m); ++i) {
      std::partial_sum(dp.cbegin(), dp.cend(), dp.begin());
    }
    return dp.back();
  }
};

} // namespace optimized

namespace combinatorics {

// Time: O(min(N, M))
// Space: O(1)
class Solution {
public:
  // Binomial(m + n - 2, n - 1)
  static int uniquePaths(int m, int n) {
    if (m > n) {
      std::swap(m, n);
    }

    long long ans = 1;
    for (int i = n; i < m + n - 1; ++i) {
      ans = ans * i / (i - n + 1);
    }
    return ans;
  }
};

} // namespace combinatorics
