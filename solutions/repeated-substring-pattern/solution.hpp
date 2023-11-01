#pragma once

#include <string>

/*
  459. Repeated Substring Pattern
  https://leetcode.com/problems/repeated-substring-pattern/
  Difficulty: Easy
  Tags: String, String Matching
  Time:
  Space:
*/

class Solution {
public:
  static bool repeatedSubstringPattern(std::string s) {
    return (s + s).find(s, 1) < s.size();
  }
};
