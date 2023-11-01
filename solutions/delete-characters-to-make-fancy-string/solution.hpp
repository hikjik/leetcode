#pragma once

#include <string>

/*
  1957. Delete Characters to Make Fancy String
  https://leetcode.com/problems/delete-characters-to-make-fancy-string/
  Difficulty: Easy
  Tags: String
  Time:
  Space:
*/

class Solution {
public:
  static std::string makeFancyString(std::string s) {
    std::string ans;
    for (size_t i = 0; i < s.size(); ++i) {
      if (i < 2 || s[i] != s[i - 1] || s[i] != s[i - 2]) {
        ans.push_back(s[i]);
      }
    }
    return ans;
  }
};
