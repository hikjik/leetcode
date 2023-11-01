#pragma once

#include <algorithm>
#include <string>
#include <vector>

/*
  2370. Longest Ideal Subsequence
  https://leetcode.com/problems/longest-ideal-subsequence/
  Difficulty: Medium
  Tags: Hash Table, String, Dynamic Programming
  Time:
  Space:
*/

class Solution {
public:
  static int longestIdealString(std::string s, int k) {
    std::vector<int> dp(26, 0);
    for (auto c : s) {
      const auto u = c - 'a';
      const auto l = std::max(u - k, 0), r = std::min(u + k, 25);

      dp[u] = 1 + *std::max_element(dp.begin() + l, dp.begin() + r + 1);
    }
    return *std::max_element(dp.begin(), dp.end());
  }
};
