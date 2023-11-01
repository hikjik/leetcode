#pragma once

#include <algorithm>
#include <string>

/*
  2000. Reverse Prefix of Word
  https://leetcode.com/problems/reverse-prefix-of-word/
  Difficulty: Easy
  Tags: Two Pointers, String
  Time:
  Space:
*/

class Solution {
public:
  static std::string reversePrefix(std::string word, char ch) {
    if (auto pos = word.find(ch); pos != std::string::npos) {
      std::reverse(word.begin(), word.begin() + pos + 1);
    }
    return word;
  }
};
