#pragma once

#include <string>

/*
  1614. Maximum Nesting Depth of the Parentheses
  https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses/
  Difficulty: Easy
  Tags: String, Stack
  Time:
  Space:
*/

class Solution {
public:
  static int maxDepth(std::string s) {
    int max_depth = 0;
    for (int depth = 0; auto c : s) {
      if (c == '(') {
        max_depth = std::max(max_depth, ++depth);
      } else if (c == ')') {
        --depth;
      }
    }
    return max_depth;
  }
};
