#pragma once

#include <algorithm>
#include <climits>
#include <vector>

/*
  1458. Max Dot Product of Two Subsequences
  https://leetcode.com/problems/max-dot-product-of-two-subsequences/
  Difficulty: Hard
  Tags: Array, Dynamic Programming
  Time:
  Space:
*/

class Solution {
public:
  static int maxDotProduct(const std::vector<int> &nums1,
                           const std::vector<int> &nums2) {
    const int n = nums1.size(), m = nums2.size();

    std::vector dp(n + 1, std::vector<int>(m + 1, INT_MIN));
    for (int i = n - 1; i >= 0; --i) {
      for (int j = m - 1; j >= 0; --j) {
        dp[i][j] = std::max({
            nums1[i] * nums2[j] + std::max(0, dp[i + 1][j + 1]),
            dp[i + 1][j],
            dp[i][j + 1],
        });
      }
    }

    return dp[0][0];
  }
};
