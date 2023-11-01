#pragma once

#include <algorithm>
#include <string>
#include <vector>

/*
  1967. Number of Strings That Appear as Substrings in Word
  https://leetcode.com/problems/number-of-strings-that-appear-as-substrings-in-word/
  Difficulty: Easy
  Tags: String
  Time:
  Space:
*/

class Solution {
public:
  static int numOfStrings(const std::vector<std::string> &patterns,
                          std::string word) {
    return std::count_if(patterns.begin(), patterns.end(), [&](const auto &p) {
      return word.find(p) != std::string::npos;
    });
  }
};
