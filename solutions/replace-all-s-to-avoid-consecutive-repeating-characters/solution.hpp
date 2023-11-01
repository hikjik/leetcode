#pragma once

#include <string>

/*
  1576. Replace All ?'s to Avoid Consecutive Repeating Characters
  https://leetcode.com/problems/replace-all-s-to-avoid-consecutive-repeating-characters/
  Difficulty: Easy
  Tags: String
  Time:
  Space:
*/

class Solution {
public:
  static std::string modifyString(std::string s) {
    for (size_t i = 0; i < s.size(); ++i) {
      if (s[i] == '?') {
        for (auto c = 'a'; c <= 'c'; ++c) {
          if ((i == 0 || s[i - 1] != c) &&
              (i + 1 == s.size() || s[i + 1] != c)) {
            s[i] = c;
            break;
          }
        }
      }
    }
    return s;
  }
};
