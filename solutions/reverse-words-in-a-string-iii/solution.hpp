#pragma once

#include <algorithm>
#include <regex>
#include <string>

/*
  557. Reverse Words in a String III
  https://leetcode.com/problems/reverse-words-in-a-string-iii/
  Difficulty: Easy
  Tags: Two Pointers, String
  Time:
  Space:
*/

class Solution {
public:
  static std::string reverseWords(std::string str) {
    auto begin = str.begin();
    std::string::iterator end;
    do {
      end = std::find(begin, str.end(), ' ');
      std::reverse(begin, end);
      begin = std::next(end);
    } while (end != str.end());
    return str;
  }
};
