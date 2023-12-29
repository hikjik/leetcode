#pragma once

#include <array>
#include <vector>

// Time: O(N^2D)
// Space: O(ND)

namespace memo {

// Time: O(N^2D)
// Space: O(ND)
class Solution {
public:
  static constexpr int kInf = 0x3f3f3f3f;

  static int minDifficulty(const std::vector<int> &jobDifficulty, int d) {
    const int n = jobDifficulty.size();
    if (n < d) {
      return -1;
    }
    std::vector memo(n + 1, std::vector<int>(d + 1, kInf));
    return minDifficulty(0, d, jobDifficulty, &memo);
  }

private:
  static int minDifficulty(int i, int r, const std::vector<int> &jobDifficulty,
                           std::vector<std::vector<int>> *memo) {
    const int n = jobDifficulty.size();
    if (i == n) {
      return r == 0 ? 0 : kInf;
    }
    if (r == 0) {
      return kInf;
    }
    auto &ans = (*memo)[i][r];
    if (ans == kInf) {
      auto maxDifficulty = jobDifficulty[i];
      for (int j = i; j <= n - r; ++j) {
        maxDifficulty = std::max(maxDifficulty, jobDifficulty[j]);
        ans = std::min(ans, maxDifficulty + minDifficulty(j + 1, r - 1,
                                                          jobDifficulty, memo));
      }
    }
    return ans;
  }
};

} // namespace memo

namespace dp {

// Time: O(N^2D)
// Space: O(ND)
class Solution {
public:
  static constexpr int kInf = 0x3f3f3f3f;

  static int minDifficulty(const std::vector<int> &jobDifficulty, int d) {
    const int n = jobDifficulty.size();
    if (n < d) {
      return -1;
    }

    std::vector dp(n + 1, std::vector<int>(d + 1, kInf));
    dp[n][0] = 0;
    for (int r = 1; r <= d; ++r) {
      for (int i = 0; i < n; ++i) {
        auto maxDifficulty = jobDifficulty[i];
        for (int j = i; j <= n - r; ++j) {
          maxDifficulty = std::max(maxDifficulty, jobDifficulty[j]);
          dp[i][r] = std::min(dp[i][r], maxDifficulty + dp[j + 1][r - 1]);
        }
      }
    }
    return dp[0][d];
  }
};

} // namespace dp
