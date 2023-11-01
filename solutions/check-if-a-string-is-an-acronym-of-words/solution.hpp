#pragma once

#include <string>
#include <vector>

/*
  2828. Check if a String Is an Acronym of Words
  https://leetcode.com/problems/check-if-a-string-is-an-acronym-of-words/
  Difficulty: Easy
  Tags: Array, String
  Time:
  Space:
*/

class Solution {
public:
  static bool isAcronym(const std::vector<std::string> &words, std::string s) {
    std::string acronym;
    for (const auto &word : words) {
      acronym += word.front();
    }
    return acronym == s;
  }
};
