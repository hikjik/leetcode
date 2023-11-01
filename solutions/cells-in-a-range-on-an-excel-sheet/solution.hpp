#pragma once

#include <string>
#include <vector>

/*
  2194. Cells in a Range on an Excel Sheet
  https://leetcode.com/problems/cells-in-a-range-on-an-excel-sheet/
  Difficulty: Easy
  Tags: String
  Time:
  Space:
*/

class Solution {
public:
  static std::vector<std::string> cellsInRange(std::string s) {
    std::vector<std::string> ans;
    for (char c = s[0]; c <= s[3]; ++c) {
      for (char r = s[1]; r <= s[4]; ++r) {
        ans.push_back({c, r});
      }
    }
    return ans;
  }
};
