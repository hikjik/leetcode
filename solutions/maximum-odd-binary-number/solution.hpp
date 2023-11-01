#pragma once

#include <algorithm>
#include <string>

/*
  2864. Maximum Odd Binary Number
  https://leetcode.com/problems/maximum-odd-binary-number/
  Difficulty: Easy
  Tags: Math, String, Greedy
  Time:
  Space:
*/

class Solution {
public:
  static std::string maximumOddBinaryNumber(std::string s) {
    const auto ones = std::count(s.begin(), s.end(), '1');
    const auto zeros = s.size() - ones;
    return std::string(ones - 1, '1') + std::string(zeros, '0') + '1';
  }
};
