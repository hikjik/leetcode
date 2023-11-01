#pragma once

#include <string>

/*
  392. Is Subsequence
  https://leetcode.com/problems/is-subsequence/
  Difficulty: Easy
  Tags: Two Pointers, String, Dynamic Programming
  Time:
  Space:
*/

class Solution {
public:
  static bool isSubsequence(std::string s, std::string t) {
    size_t pos = 0;
    size_t count = 0;
    for (auto c : s) {
      pos = t.find(c, pos);
      if (pos == std::string::npos) {
        break;
      }
      pos++;
      count++;
    }
    return count == s.size();
  }
};
