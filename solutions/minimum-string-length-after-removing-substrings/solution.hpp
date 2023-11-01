#pragma once

#include <string>

/*
  2696. Minimum String Length After Removing Substrings
  https://leetcode.com/problems/minimum-string-length-after-removing-substrings/
  Difficulty: Easy
  Tags: String, Stack, Simulation
  Time:
  Space:
*/

class Solution {
public:
  static int minLength(std::string s) {
    std::string stack;
    for (auto c : s) {
      if (!stack.empty() && (c == 'B' && stack.back() == 'A' ||
                             c == 'D' && stack.back() == 'C')) {
        stack.pop_back();
      } else {
        stack.push_back(c);
      }
    }
    return stack.size();
  }
};
