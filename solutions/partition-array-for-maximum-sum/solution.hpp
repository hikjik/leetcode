#pragma once

#include <vector>

// Time: O(NK)
// Space: O(N)

namespace memo {

// Time: O(NK)
// Space: O(N)
class Solution {
public:
  static int maxSumAfterPartitioning(const std::vector<int> &arr, int k) {
    std::vector<int> memo(arr.size(), -1);
    return (maxSum(0, arr, k, &memo));
  }

private:
  static int maxSum(int i, const std::vector<int> &arr, int k,
                    std::vector<int> *memo) {
    const int n = arr.size();
    if (i == n) {
      return 0;
    }
    auto &sum = (*memo)[i];
    if (sum == -1) {
      sum = 0;
      int max = arr[i];
      for (int j = 1; i + j - 1 < n && j <= k; ++j) {
        max = std::max(max, arr[i + j - 1]);
        sum = std::max(sum, max * j + maxSum(i + j, arr, k, memo));
      }
    }
    return sum;
  }
};

} // namespace memo

namespace dp {

// Time: O(NK)
// Space: O(N)
class Solution {
public:
  static int maxSumAfterPartitioning(const std::vector<int> &arr, int k) {
    const int n = arr.size();
    std::vector<int> dp(n + 1);
    for (int i = n - 1; i >= 0; --i) {
      auto max = arr[i];
      for (int j = 1; i + j - 1 < n && j <= k; ++j) {
        max = std::max(max, arr[i + j - 1]);
        dp[i] = std::max(dp[i], max * j + dp[i + j]);
      }
    }
    return dp[0];
  }
};

} // namespace dp
