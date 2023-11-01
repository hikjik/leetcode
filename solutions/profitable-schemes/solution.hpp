#pragma once

#include <algorithm>
#include <cstring>
#include <vector>

/*
  879. Profitable Schemes
  https://leetcode.com/problems/profitable-schemes/
  Difficulty: Hard
  Tags: Array, Dynamic Programming
  Time:
  Space:
*/

class Solution {
  static const int kMod = 1e9 + 7;
  static inline int dp[101][101][101];

public:
  static int profitableSchemes(int n, int minProfit,
                               const std::vector<int> &group,
                               const std::vector<int> &profit) {
    std::memset(dp, -1, sizeof(dp));
    return countSchemes(0, 0, 0, n, minProfit, group, profit);
  }

private:
  static int countSchemes(size_t index, int curProfit, int membersCount, int n,
                          int minProfit, const std::vector<int> &group,
                          const std::vector<int> &profit) {
    if (index == group.size()) {
      return curProfit >= minProfit;
    }

    auto &count = dp[index][curProfit][membersCount];
    if (count != -1) {
      return count;
    }

    count = countSchemes(index + 1, curProfit, membersCount, n, minProfit,
                         group, profit);
    if (membersCount + group[index] <= n) {
      count += countSchemes(
          index + 1, std::min(minProfit, curProfit + profit[index]),
          membersCount + group[index], n, minProfit, group, profit);
    }
    count %= kMod;
    return count;
  }
};
