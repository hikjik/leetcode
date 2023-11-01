#pragma once

#include <string>

/*
  1544. Make The String Great
  https://leetcode.com/problems/make-the-string-great/
  Difficulty: Easy
  Tags: String, Stack
  Time:
  Space:
*/

class Solution {
public:
  static std::string makeGood(std::string s) {
    std::string ans;
    for (auto c : s) {
      if (!ans.empty() && isFlipCase(ans.back(), c)) {
        ans.pop_back();
      } else {
        ans.push_back(c);
      }
    }
    return ans;
  }

private:
  static bool isFlipCase(char a, char b) {
    return a != b && std::tolower(a) == std::tolower(b);
  }
};
