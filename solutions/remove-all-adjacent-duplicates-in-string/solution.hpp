#pragma once

#include <string>

/*
  1047. Remove All Adjacent Duplicates In String
  https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/
  Difficulty: Easy
  Tags: String, Stack
  Time:
  Space:
*/

class Solution {
public:
  static std::string removeDuplicates(std::string s) {
    std::string ans;
    for (auto c : s) {
      if (!ans.empty() && ans.back() == c) {
        ans.pop_back();
      } else {
        ans.push_back(c);
      }
    }
    return ans;
  }
};
