#pragma once

#include <algorithm>
#include <string>

/*
  520. Detect Capital
  https://leetcode.com/problems/detect-capital/
  Difficulty: Easy
  Tags: String
  Time:
  Space:
*/

class Solution {
public:
  static bool detectCapitalUse(std::string word) {
    return std::all_of(word.begin(), word.end(),
                       [](unsigned char c) { return std::isupper(c); }) ||
           std::all_of(word.begin() + 1, word.end(),
                       [](unsigned char c) { return std::islower(c); });
  }
};
