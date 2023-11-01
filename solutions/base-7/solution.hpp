#pragma once

#include <cmath>
#include <string>

/*
  504. Base 7
  https://leetcode.com/problems/base-7/
  Difficulty: Easy
  Tags: Math
  Time:
  Space:
*/

class Solution {
public:
  static std::string convertToBase7(int num) {
    if (!num) {
      return "0";
    }
    if (num < 0) {
      return "-" + convertToBase7(-num);
    }

    std::string ans;
    for (int i = num; i; i /= 7) {
      ans.push_back('0' + (i % 7));
    }
    std::reverse(ans.begin(), ans.end());
    return ans;
  }
};
