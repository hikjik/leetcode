#pragma once

#include <algorithm>
#include <limits>
#include <string>
#include <vector>

class Solution {
private:
  const size_t kMaxStones = 3;

public:
  std::string stoneGameIII(const std::vector<int> &stone_values) {
    const int n = stone_values.size();

    std::vector<int> dp(n + 1, std::numeric_limits<int>::min());
    dp.back() = 0;

    for (int i = n - 1; i >= 0; --i) {
      int sum = 0;
      for (int j = i + 1; j <= std::min(i + 3, n); ++j) {
        sum += stone_values[j - 1];
        dp[i] = std::max(dp[i], sum - dp[j]);
      }
    }

    return dp.front() > 0 ? "Alice" : dp.front() < 0 ? "Bob" : "Tie";
  }
};
