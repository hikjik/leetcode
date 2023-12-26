#pragma once

#include <bit>
#include <vector>

// Time: O(N2^N)
// Space: O(2^N)

namespace memo {

// Time: O(N2^N)
// Space: O(2^N)
class Solution {
public:
  static int countArrangement(int n) {
    std::vector<int> memo(1 << n, -1);
    memo.back() = 1;
    return countArrangement(0, n, &memo);
  }

private:
  static int countArrangement(unsigned mask, int n, std::vector<int> *memo) {
    auto &cnt = (*memo)[mask];
    if (cnt == -1) {
      cnt = 0;
      const int i = std::popcount(mask) + 1;
      for (int j = 1; j <= n; ++j) {
        if (!(mask & (1 << (j - 1))) && (j % i == 0 || i % j == 0)) {
          cnt += countArrangement(mask | 1 << (j - 1), n, memo);
        }
      }
    }
    return cnt;
  }
};

} // namespace memo

namespace dp {

// Time: O(N2^N)
// Space: O(2^N)
class Solution {
public:
  static int countArrangement(int n) {
    std::vector<int> dp(1 << n);
    dp[0] = 1;
    for (unsigned mask = 0; mask < std::ssize(dp); ++mask) {
      const int i = std::popcount(mask) + 1;
      for (int j = 1; j <= n; ++j) {
        if (!(mask & (1 << (j - 1))) && (j % i == 0 || i % j == 0)) {
          dp[mask | (1 << (j - 1))] += dp[mask];
        }
      }
    }
    return dp.back();
  }
};

} // namespace dp
