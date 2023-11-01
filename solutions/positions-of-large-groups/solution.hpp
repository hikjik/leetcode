#pragma once

#include <string>
#include <vector>

/*
  830. Positions of Large Groups
  https://leetcode.com/problems/positions-of-large-groups/
  Difficulty: Easy
  Tags: String
  Time:
  Space:
*/

class Solution {
public:
  static std::vector<std::vector<int>> largeGroupPositions(std::string s) {
    std::vector<std::vector<int>> ans;
    for (int i = 0, j = 0; i < std::ssize(s); i = j) {
      while (j < std::ssize(s) && s[j] == s[i]) {
        ++j;
      }
      if (j - i > 2) {
        ans.push_back({i, j - 1});
      }
    }
    return ans;
  }
};
