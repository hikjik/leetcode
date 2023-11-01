#pragma once

#include <vector>

/*
  216. Combination Sum III
  https://leetcode.com/problems/combination-sum-iii/
  Difficulty: Medium
  Tags: Array, Backtracking
  Time:
  Space:
*/

class Solution {
public:
  static std::vector<std::vector<int>> combinationSum3(int k, int n) {
    std::vector<std::vector<int>> combinations;
    std::vector<int> combination;
    dfs(k, n, 1, &combinations, &combination);
    return combinations;
  }

private:
  static void dfs(int k, int n, int i,
                  std::vector<std::vector<int>> *combinations,
                  std::vector<int> *combination) {
    if (!k && !n) {
      combinations->push_back(*combination);
      return;
    }
    if (!k || n < 0 || i > 9) {
      return;
    }

    combination->push_back(i);
    dfs(k - 1, n - i, i + 1, combinations, combination);
    combination->pop_back();
    dfs(k, n, i + 1, combinations, combination);
  }
};
