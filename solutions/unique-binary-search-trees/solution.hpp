#pragma once

#include <vector>

/*
  96. Unique Binary Search Trees
  https://leetcode.com/problems/unique-binary-search-trees/
  Difficulty: Medium
  Tags: Math, Dynamic Programming, Tree, Binary Search Tree, Binary Tree
  Time:
  Space:
*/

class Solution {
public:
  static int numTrees(int n) {
    std::vector<int> dp(n + 1, 0);
    dp[0] = dp[1] = 1;

    for (int i = 2; i <= n; ++i) {
      for (int j = 1; j <= i; ++j) {
        dp[i] += dp[j - 1] * dp[i - j];
      }
    }

    return dp[n];
  }
};
