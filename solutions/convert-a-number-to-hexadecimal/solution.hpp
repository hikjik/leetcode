#pragma once

#include <ios>
#include <sstream>
#include <string>

/*
  405. Convert a Number to Hexadecimal
  https://leetcode.com/problems/convert-a-number-to-hexadecimal/
  Difficulty: Easy
  Tags: Math, Bit Manipulation
  Time:
  Space:
*/

class Solution {
public:
  static std::string toHex(int num) {
    std::stringstream sstream;
    sstream << std::hex << num;
    return sstream.str();
  }
};
