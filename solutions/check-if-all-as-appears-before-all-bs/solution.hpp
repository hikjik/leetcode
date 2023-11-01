#pragma once

#include <string>

/*
  2124. Check if All A's Appears Before All B's
  https://leetcode.com/problems/check-if-all-as-appears-before-all-bs/
  Difficulty: Easy
  Tags: String
  Time:
  Space:
*/

class Solution {
public:
  static bool checkString(std::string s) {
    for (size_t i = 0; i + 1 < s.size(); ++i) {
      if (s[i] == 'b' && s[i + 1] == 'a') {
        return false;
      }
    }
    return true;
  }
};
