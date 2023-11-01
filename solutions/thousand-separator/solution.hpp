#pragma once

#include <string>

/*
  1556. Thousand Separator
  https://leetcode.com/problems/thousand-separator/
  Difficulty: Easy
  Tags: String
  Time:
  Space:
*/

class Solution {
public:
  static std::string thousandSeparator(int n) {
    auto s = std::to_string(n);
    std::string ans;
    for (size_t i = 0; i < s.size(); ++i) {
      if (i && i % 3 == 0) {
        ans += '.';
      }
      ans += s[s.size() - i - 1];
    }
    std::reverse(ans.begin(), ans.end());
    return ans;
  }
};
