#pragma once

#include <string>

/*
  1221. Split a String in Balanced Strings
  https://leetcode.com/problems/split-a-string-in-balanced-strings/
  Difficulty: Easy
  Tags: String, Greedy, Counting
  Time:
  Space:
*/

class Solution {
public:
  static int balancedStringSplit(std::string s) {
    int ans = 0, cnt = 0;
    for (auto c : s) {
      cnt += c == 'R' ? 1 : -1;
      ans += !cnt;
    }
    return ans;
  }
};
