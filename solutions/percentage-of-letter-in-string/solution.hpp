#pragma once

#include <string>

/*
  2278. Percentage of Letter in String
  https://leetcode.com/problems/percentage-of-letter-in-string/
  Difficulty: Easy
  Tags: String
  Time:
  Space:
*/

class Solution {
public:
  static int percentageLetter(std::string s, char letter) {
    return 100 * std::count(s.begin(), s.end(), letter) / s.size();
  }
};
