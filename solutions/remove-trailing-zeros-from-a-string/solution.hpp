#pragma once

#include <string>

/*
  2710. Remove Trailing Zeros From a String
  https://leetcode.com/problems/remove-trailing-zeros-from-a-string/
  Difficulty: Easy
  Tags: String
  Time:
  Space:
*/

class Solution {
public:
  static std::string removeTrailingZeros(std::string num) {
    return num.substr(0, num.find_last_not_of('0') + 1);
  }
};
