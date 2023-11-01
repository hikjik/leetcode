#pragma once

#include <algorithm>
#include <string>

/*
  709. To Lower Case
  https://leetcode.com/problems/to-lower-case/
  Difficulty: Easy
  Tags: String
  Time:
  Space:
*/

class Solution {
public:
  static std::string toLowerCase(std::string s) {
    std::transform(s.begin(), s.end(), s.begin(),
                   [](unsigned char c) { return std::tolower(c); });
    return s;
  }
};
