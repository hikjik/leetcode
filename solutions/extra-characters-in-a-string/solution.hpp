#pragma once

#include <algorithm>
#include <string>
#include <unordered_set>
#include <vector>

/*
  2707. Extra Characters in a String
  https://leetcode.com/problems/extra-characters-in-a-string/
  Difficulty: Medium
  Tags: Array, Hash Table, String, Dynamic Programming, Trie
  Time:
  Space:
*/

class Solution {
public:
  static int minExtraChar(std::string s,
                          const std::vector<std::string> &dictionary) {
    const int n = s.size();
    const std::unordered_set<std::string> words{dictionary.begin(),
                                                dictionary.end()};

    std::vector<int> dp(n + 1);
    for (int i = 1; i <= n; ++i) {
      dp[i] = n;
      for (int j = 0; j < i; ++j) {
        const auto extra = words.count(s.substr(j, i - j)) ? 0 : i - j;
        dp[i] = std::min(dp[i], dp[j] + extra);
      }
    }
    return dp.back();
  }
};
