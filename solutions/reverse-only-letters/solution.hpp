#pragma once

#include <string>

/*
  917. Reverse Only Letters
  https://leetcode.com/problems/reverse-only-letters/
  Difficulty: Easy
  Tags: Two Pointers, String
  Time:
  Space:
*/

class Solution {
public:
  static std::string reverseOnlyLetters(std::string s) {
    for (int i = 0, j = std::ssize(s) - 1; i < j; ++i, --j) {
      while (i < j && !std::isalpha(s[i])) {
        ++i;
      }
      while (i < j && !std::isalpha(s[j])) {
        --j;
      }
      std::swap(s[i], s[j]);
    }
    return s;
  }
};