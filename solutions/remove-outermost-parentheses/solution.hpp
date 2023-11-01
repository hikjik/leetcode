#pragma once

#include <string>

/*
  1021. Remove Outermost Parentheses
  https://leetcode.com/problems/remove-outermost-parentheses/
  Difficulty: Easy
  Tags: String, Stack
  Time:
  Space:
*/

class Solution {
public:
  static std::string removeOuterParentheses(std::string s) {
    std::string ans;
    int cnt = 0;
    for (auto c : s) {
      if (c == '(' && cnt++ || c == ')' && --cnt) {
        ans.push_back(c);
      }
    }
    return ans;
  }
};
