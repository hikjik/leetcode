#pragma once

#include <vector>

// Time: O(N^3)
// Space: O(N^2)

namespace memo {

// Time: O(N^3)
// Space: O(N^2)
class Solution {
public:
  static int maxCoins(std::vector<int> nums) {
    const int n = nums.size();

    nums.insert(nums.begin(), 1);
    nums.push_back(1);

    std::vector memo(n + 2, std::vector<int>(n + 2));
    return maxCoins(1, n, nums, &memo);
  }

private:
  static int maxCoins(int i, int j, const std::vector<int> &nums,
                      std::vector<std::vector<int>> *memo) {
    if (i > j) {
      return 0;
    }
    auto &coins = (*memo)[i][j];
    if (!coins) {
      for (int k = i; k <= j; ++k) {
        coins = std::max(coins, nums[i - 1] * nums[k] * nums[j + 1] +
                                    maxCoins(i, k - 1, nums, memo) +
                                    maxCoins(k + 1, j, nums, memo));
      }
    }
    return coins;
  }
};

} // namespace memo

namespace dp {

// Time: O(N^3)
// Space: O(N^2)
class Solution {
public:
  static int maxCoins(std::vector<int> nums) {
    const int n = nums.size();

    nums.insert(nums.begin(), 1);
    nums.push_back(1);

    std::vector dp(n + 2, std::vector<int>(n + 2));
    for (int l = 0; l < n; ++l) {
      for (int i = 1; i + l <= n; ++i) {
        const int j = i + l;
        for (int k = i; k <= j; ++k) {
          dp[i][j] = std::max(dp[i][j], nums[i - 1] * nums[k] * nums[j + 1] +
                                            dp[i][k - 1] + dp[k + 1][j]);
        }
      }
    }
    return dp[1][n];
  }
};

} // namespace dp
