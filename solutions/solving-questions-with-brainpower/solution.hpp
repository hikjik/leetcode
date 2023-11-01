#pragma once

#include <algorithm>
#include <vector>

/*
  2140. Solving Questions With Brainpower
  https://leetcode.com/problems/solving-questions-with-brainpower/
  Difficulty: Medium
  Tags: Array, Dynamic Programming
  Time:
  Space:
*/

class Solution {
public:
  static long long mostPoints(const std::vector<std::vector<int>> &questions) {
    const int n = questions.size();
    std::vector<long long> dp(n + 1, 0);
    for (int i = n - 1; i >= 0; --i) {
      const auto points = questions[i][0];
      const auto brainpower = questions[i][1];
      const auto next = i + brainpower + 1;
      dp[i] = std::max(dp[i + 1], (next < n ? dp[next] : 0) + points);
    }
    return dp.front();
  }
};
