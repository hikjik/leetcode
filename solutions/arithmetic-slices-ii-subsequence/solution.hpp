#pragma once

#include <unordered_map>
#include <vector>

// Time: O(N^2)
// Space: O(N^2)

class Solution {
public:
  static int numberOfArithmeticSlices(const std::vector<int> &nums) {
    const int n = nums.size();
    std::vector<std::unordered_map<long long, int>> dp(n);
    int ans = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < i; ++j) {
        const auto diff = 0LL + nums[i] - nums[j];
        const auto cnt = dp[j].contains(diff) ? dp[j][diff] : 0;
        ans += cnt;
        dp[i][diff] += 1 + cnt;
      }
    }
    return ans;
  }
};
