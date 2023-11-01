#pragma once

#include <string>

/*
  58. Length of Last Word
  https://leetcode.com/problems/length-of-last-word/
  Difficulty: Easy
  Tags: String
  Time:
  Space:
*/

class Solution {
public:
  static int lengthOfLastWord(std::string s) {
    int i = s.size() - 1;
    while (i >= 0 && std::isspace(s[i])) {
      --i;
    }
    int j = i;
    while (j >= 0 && !std::isspace(s[j])) {
      --j;
    }
    return i - j;
  }
};
