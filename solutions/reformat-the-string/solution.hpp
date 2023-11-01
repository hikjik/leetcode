#pragma once

#include <string>

/*
  1417. Reformat The String
  https://leetcode.com/problems/reformat-the-string/
  Difficulty: Easy
  Tags: String
  Time:
  Space:
*/

class Solution {
public:
  static std::string reformat(std::string s) {
    std::vector<int> cnt(2);
    for (auto c : s) {
      ++cnt[std::isdigit(c)];
    }

    if (std::abs(cnt[0] - cnt[1]) > 1) {
      return "";
    }

    std::string ans(s);
    for (int i = -2, j = -1; auto c : s) {
      ans[std::isdigit(c) == cnt[1] >= cnt[0] ? i += 2 : j += 2] = c;
    }
    return ans;
  }
};
