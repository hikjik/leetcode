#pragma once

#include <vector>

// Time: O(NK)
// Space: O(K)

namespace memo {

// Time: O(NK)
// Space: O(NK)
class Solution {
public:
  static int rearrangeSticks(int n, int k) {
    std::vector memo(n + 1, std::vector<int>(k + 1));
    return rearrangeSticks(n, k, &memo);
  }

private:
  static constexpr int kMod = 1e9 + 7;

  static int rearrangeSticks(int n, int k,
                             std::vector<std::vector<int>> *memo) {
    if (k == n) {
      return 1;
    }
    auto &ans = (*memo)[n][k];
    if (k > 0 && n > k && !ans) {
      ans = (rearrangeSticks(n - 1, k - 1, memo) +
             (n - 1LL) * rearrangeSticks(n - 1, k, memo)) %
            kMod;
    }
    return ans;
  }
};

} // namespace memo

namespace dp {

// Time: O(NK)
// Space: O(NK)
class Solution {
private:
  static constexpr int kMod = 1e9 + 7;

public:
  static int rearrangeSticks(int n, int k) {
    std::vector dp(n + 1, std::vector<int>(k + 1));
    dp[0][0] = 1;
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= k; ++j) {
        dp[i][j] = (dp[i - 1][j - 1] + (i - 1LL) * dp[i - 1][j]) % kMod;
      }
    }
    return dp[n][k];
  }
};

} // namespace dp

namespace optimized {

// Time: O(NK)
// Space: O(K)
class Solution {
private:
  static constexpr int kMod = 1e9 + 7;

public:
  static int rearrangeSticks(int n, int k) {
    std::vector<int> dp(k + 1);
    for (int i = 1; i <= n; ++i) {
      int prev = i == 1;
      for (int j = 1; j <= k; ++j) {
        prev = std::exchange(dp[j], (prev + (i - 1LL) * dp[j]) % kMod);
      }
    }
    return dp[k];
  }
};

} // namespace optimized
