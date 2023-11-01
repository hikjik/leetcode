#pragma once

#include <string>

/*
  2259. Remove Digit From Number to Maximize Result
  https://leetcode.com/problems/remove-digit-from-number-to-maximize-result/
  Difficulty: Easy
  Tags: String, Greedy, Enumeration
  Time:
  Space:
*/

class Solution {
public:
  static std::string removeDigit(std::string number, char digit) {
    for (size_t i = 0; i + 1 < number.size(); ++i) {
      if (number[i] == digit && number[i] < number[i + 1]) {
        return number.erase(i, 1);
      }
    }
    return number.erase(number.rfind(digit), 1);
  }
};
