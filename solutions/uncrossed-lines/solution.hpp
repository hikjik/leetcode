#pragma once

#include <algorithm>
#include <vector>

class Solution {
public:
  static int maxUncrossedLines(const std::vector<int> &nums1,
                               const std::vector<int> &nums2) {
    const int n1 = nums1.size(), n2 = nums2.size();
    std::vector<int> dp(n2 + 1, 0);
    for (int i = 1; i <= n1; ++i) {
      int top_left = dp[0];
      for (int j = 1; j <= n2; ++j) {
        std::swap(top_left, dp[j]);
        if (nums1[i - 1] == nums2[j - 1]) {
          ++dp[j];
        } else {
          dp[j] = std::max(dp[j - 1], top_left);
        }
      }
    }
    return dp.back();
  }
};
