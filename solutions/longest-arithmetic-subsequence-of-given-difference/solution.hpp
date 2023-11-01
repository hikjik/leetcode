#pragma once

#include <algorithm>
#include <unordered_map>
#include <vector>

/*
  1218. Longest Arithmetic Subsequence of Given Difference
  https://leetcode.com/problems/longest-arithmetic-subsequence-of-given-difference/
  Difficulty: Medium
  Tags: Array, Hash Table, Dynamic Programming
  Time:
  Space:
*/

class Solution {
public:
  static int longestSubsequence(const std::vector<int> &arr, int difference) {
    int max_length = 0;
    std::unordered_map<int, int> map;
    for (auto a : arr) {
      map[a] = map[a - difference] + 1;
      max_length = std::max(max_length, map[a]);
    }
    return max_length;
  }
};
