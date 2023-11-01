#pragma once

#include <string>

/*
  796. Rotate String
  https://leetcode.com/problems/rotate-string/
  Difficulty: Easy
  Tags: String, String Matching
  Time:
  Space:
*/

class Solution {
public:
  static bool rotateString(std::string s, std::string goal) {
    return s.size() == goal.size() && (s + s).find(goal) != std::string::npos;
  }
};
