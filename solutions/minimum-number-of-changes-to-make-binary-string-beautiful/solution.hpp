#pragma once

#include <string>

/*
  2914. Minimum Number of Changes to Make Binary String Beautiful
  https://leetcode.com/problems/minimum-number-of-changes-to-make-binary-string-beautiful/
  Difficulty: Medium
  Tags: String, Greedy
  Time:
  Space:
*/

class Solution {
public:
  static int minChanges(std::string s) {
    int cnt = 0;
    for (int i = 0; i < std::ssize(s); i += 2) {
      cnt += s[i] != s[i + 1];
    }
    return cnt;
  }
};
