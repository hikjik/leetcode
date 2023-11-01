#pragma once

#include <string>
#include <vector>

/*
  6. Zigzag Conversion
  https://leetcode.com/problems/zigzag-conversion/
  Difficulty: Medium
  Tags: String
  Time:
  Space:
*/

class Solution {
public:
  static std::string convert(std::string s, int numRows) {
    if (numRows == 1 || numRows >= std::ssize(s)) {
      return s;
    }

    std::string ans;
    for (int i = 0, step = 2 * numRows - 2; i < numRows; ++i) {
      for (int j = i; j < std::ssize(s); j += step) {
        ans.push_back(s[j]);
        if (i != 0 && i != numRows - 1) {
          const auto k = j + step - 2 * i;
          if (k < std::ssize(s)) {
            ans.push_back(s[k]);
          }
        }
      }
    }
    return ans;
  }
};
