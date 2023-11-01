#pragma once

#include <string>

/*
  1784. Check if Binary String Has at Most One Segment of Ones
  https://leetcode.com/problems/check-if-binary-string-has-at-most-one-segment-of-ones/
  Difficulty: Easy
  Tags: String
  Time:
  Space:
*/

class Solution {
public:
  static bool checkOnesSegment(std::string s) {
    for (int i = 0; i + 1 < std::ssize(s); ++i) {
      if (s[i] == '0' && s[i + 1] == '1') {
        return false;
      }
    }
    return true;
  }
};
