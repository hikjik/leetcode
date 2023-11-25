#pragma once

#include <climits>
#include <deque>
#include <vector>

// Time: O(N)
// Space: O(N)

namespace memo {

// Time: O(N^2)
// Space: O(N)
class Solution {
public:
  static int minimumCoins(const std::vector<int> &prices) {
    std::vector<int> memo(prices.size(), -1);
    return minimumCoins(0, prices, &memo);
  }

private:
  static int minimumCoins(int i, const std::vector<int> &prices,
                          std::vector<int> *memo) {
    const int n = prices.size();
    if (i == n) {
      return 0;
    }

    auto &coins = (*memo)[i];
    if (coins == -1) {
      coins = INT_MAX;
      for (int j = i + 1; j <= n && j <= 2 * i + 2; ++j) {
        coins = std::min(coins, minimumCoins(j, prices, memo));
      }
      coins += prices[i];
    }
    return coins;
  }
};

} // namespace memo

namespace dp {

// Time: O(N^2)
// Space: O(N)
class Solution {
public:
  static int minimumCoins(const std::vector<int> &prices) {
    const int n = prices.size();
    std::vector<int> dp(n + 1);
    for (int i = n - 1; i >= 0; --i) {
      const auto j = std::min(n, 2 * i + 2);
      dp[i] =
          prices[i] + *std::min_element(dp.begin() + i + 1, dp.begin() + j + 1);
    }
    return dp[0];
  }
};

} // namespace dp

namespace track_minimum {

// Time: O(N)
// Space: O(N)
class Solution {
public:
  static int minimumCoins(const std::vector<int> &prices) {
    const int n = prices.size();
    std::vector<int> dp(n + 1);
    std::deque<int> deque{{n}};
    for (int i = n - 1; i >= 0; i--) {
      const auto j = std::min(n, 2 * i + 2);
      while (deque.back() > j) {
        deque.pop_back();
      }

      dp[i] = prices[i] + dp[deque.back()];

      while (dp[i] <= dp[deque.front()]) {
        deque.pop_front();
      }
      deque.push_front(i);
    }
    return dp[0];
  }
};

} // namespace track_minimum
