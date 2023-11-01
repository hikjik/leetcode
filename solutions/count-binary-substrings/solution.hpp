#pragma once

#include <string>

/*
  696. Count Binary Substrings
  https://leetcode.com/problems/count-binary-substrings/
  Difficulty: Easy
  Tags: Two Pointers, String
  Time:
  Space:
*/

class Solution {
public:
  static int countBinarySubstrings(std::string s) {
    int ans = 0;
    for (int i = 0, prev = 0, curr = 1; i < std::ssize(s); ++i) {
      if (i + 1 == std::ssize(s) || s[i] != s[i + 1]) {
        ans += std::min(prev, curr);
        prev = curr, curr = 1;
      } else {
        ++curr;
      }
    }
    return ans;
  }
};
