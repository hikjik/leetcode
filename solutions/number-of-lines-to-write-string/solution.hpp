#pragma once

#include <string>
#include <vector>

/*
  806. Number of Lines To Write String
  https://leetcode.com/problems/number-of-lines-to-write-string/
  Difficulty: Easy
  Tags: Array, String
  Time:
  Space:
*/

class Solution {
public:
  static constexpr int kMaxLineSize = 100;

  static std::vector<int> numberOfLines(const std::vector<int> &widths,
                                        std::string s) {
    int lines = 1, width = 0;
    for (auto c : s) {
      width += widths[c - 'a'];
      if (width > kMaxLineSize) {
        ++lines;
        width = widths[c - 'a'];
      }
    }
    return {lines, width};
  }
};
