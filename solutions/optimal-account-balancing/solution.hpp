#pragma once

#include <climits>
#include <functional>
#include <vector>

// Time: O(N2^N)
// Space: O(2^N)

namespace backtracing {

// Time: O(N!)
// Space: O(N)
class Solution {
public:
  static int minTransfers(const std::vector<std::vector<int>> &transactions) {
    std::vector<int> balances(12);
    for (const auto &t : transactions) {
      balances[t[0]] -= t[2];
      balances[t[1]] += t[2];
    }
    std::erase(balances, 0);
    const int n = balances.size();

    std::function<int(int)> dfs = [&](int i) {
      while (i < n && !balances[i]) {
        ++i;
      }
      if (i == n) {
        return 0;
      }
      int cost = INT_MAX / 2;
      for (int j = i + 1; j < n; ++j) {
        if (balances[i] > 0 != balances[j] > 0) {
          balances[j] += balances[i];
          cost = std::min(cost, 1 + dfs(i + 1));
          balances[j] -= balances[i];
        }
      }
      return cost;
    };

    return dfs(0);
  }
};

} // namespace backtracing

namespace memo {

// Time: O(N2^N)
// Space: O(2^N)
class Solution {
public:
  static int minTransfers(const std::vector<std::vector<int>> &transactions) {
    std::vector<int> balances(12);
    for (const auto &t : transactions) {
      balances[t[0]] -= t[2];
      balances[t[1]] += t[2];
    }
    std::erase(balances, 0);
    const int n = balances.size();

    std::vector<int> memo(1 << n, -1);
    memo[0] = 0;

    std::function<int(int)> dfs = [&](int mask) {
      if (memo[mask] != -1) {
        return memo[mask];
      }

      int sum = 0, cost = 0;
      for (int i = 0; i < n; ++i) {
        if (mask & 1 << i) {
          sum += balances[i];
          cost = std::max(cost, dfs(mask ^ 1 << i));
        }
      }
      return memo[mask] = cost + !sum;
    };

    return n - dfs(memo.size() - 1);
  }
};

} // namespace memo

namespace dp {

// Time: O(N2^N)
// Space: O(2^N)
class Solution {
public:
  static int minTransfers(const std::vector<std::vector<int>> &transactions) {
    std::vector<int> balances(12);
    for (const auto &t : transactions) {
      balances[t[0]] -= t[2];
      balances[t[1]] += t[2];
    }
    std::erase(balances, 0);
    const int n = balances.size();

    std::vector<int> dp(1 << n);
    for (int mask = 1; mask < 1 << n; ++mask) {
      int sum = 0, cost = 0;
      for (int i = 0; i < n; ++i) {
        if (mask & 1 << i) {
          sum += balances[i];
          cost = std::max(cost, dp[mask ^ 1 << i]);
        }
      }
      dp[mask] = cost + !sum;
    }
    return n - dp.back();
  }
};

} // namespace dp
