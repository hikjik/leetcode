#pragma once

#include <string>

/*
  1422. Maximum Score After Splitting a String
  https://leetcode.com/problems/maximum-score-after-splitting-a-string/
  Difficulty: Easy
  Tags: String
  Time:
  Space:
*/

class Solution {
public:
  static int maxScore(std::string s) {
    int left = 0, right = std::count(s.begin(), s.end(), '1');
    int score = 0;
    for (int i = 0; i + 1 < std::ssize(s); ++i) {
      s[i] == '0' ? ++left : --right;
      score = std::max(score, left + right);
    }
    return score;
  }
};
