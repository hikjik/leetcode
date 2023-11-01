#pragma once

#include <string>

/*
  1844. Replace All Digits with Characters
  https://leetcode.com/problems/replace-all-digits-with-characters/
  Difficulty: Easy
  Tags: String
  Time:
  Space:
*/

class Solution {
public:
  static std::string replaceDigits(std::string s) {
    for (int i = 1; i < std::ssize(s); i += 2) {
      s[i] = s[i - 1] + s[i] - '0';
    }
    return s;
  }
};
