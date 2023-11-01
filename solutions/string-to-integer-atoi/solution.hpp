#pragma once

#include <sstream>
#include <string>

/*
  8. String to Integer (atoi)
  https://leetcode.com/problems/string-to-integer-atoi/
  Difficulty: Medium
  Tags: String
  Time:
  Space:
*/

class Solution {
public:
  static int myAtoi(std::string s) {
    std::stringstream stream(s);
    int number;
    stream >> number;
    return number;
  }
};
