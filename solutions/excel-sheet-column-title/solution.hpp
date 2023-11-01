#pragma once

#include <algorithm>
#include <string>

/*
  168. Excel Sheet Column Title
  https://leetcode.com/problems/excel-sheet-column-title/
  Difficulty: Easy
  Tags: Math, String
  Time:
  Space:
*/

class Solution {
private:
  static const int kAlphabetSize = 26;

public:
  static std::string convertToTitle(int columnNumber) {
    std::string title;
    while (columnNumber--) {
      title += 'A' + columnNumber % kAlphabetSize;
      columnNumber /= kAlphabetSize;
    }
    std::reverse(title.begin(), title.end());
    return title;
  }
};
