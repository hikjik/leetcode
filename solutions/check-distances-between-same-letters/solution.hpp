#pragma once

#include <string>
#include <vector>

/*
  2399. Check Distances Between Same Letters
  https://leetcode.com/problems/check-distances-between-same-letters/
  Difficulty: Easy
  Tags: Array, Hash Table, String
  Time:
  Space:
*/

class Solution {
public:
  static bool checkDistances(std::string s, const std::vector<int> &distance) {
    const int n = s.size();

    std::vector<int> actual(26, -1);
    for (int i = 0; i < n; ++i) {
      const int idx = s[i] - 'a';
      if (actual[idx] != -1 && i - actual[idx] - 1 != distance[idx]) {
        return false;
      }
      actual[idx] = i;
    }

    return true;
  }
};
