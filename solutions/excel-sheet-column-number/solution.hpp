#pragma once

#include <string>

/*
  171. Excel Sheet Column Number
  https://leetcode.com/problems/excel-sheet-column-number/
  Difficulty: Easy
  Tags: Math, String
  Time:
  Space:
*/

class Solution {
public:
  static int titleToNumber(std::string columnTitle) {
    int number = 0;
    for (auto c : columnTitle) {
      number = number * 26 + (c - 'A' + 1);
    }
    return number;
  }
};
