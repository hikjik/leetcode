#pragma once

#include <unordered_map>
#include <vector>

/*
  1128. Number of Equivalent Domino Pairs
  https://leetcode.com/problems/number-of-equivalent-domino-pairs/
  Difficulty: Easy
  Tags: Array, Hash Table, Counting
  Time:
  Space:
*/

class Solution {
public:
  static int
  numEquivDominoPairs(const std::vector<std::vector<int>> &dominoes) {
    std::unordered_map<int, int> map;
    int ans = 0;
    for (const auto &domino : dominoes) {
      ans += map[1 << domino[0] | 1 << domino[1]]++;
    }
    return ans;
  }
};
