#pragma once

#include <algorithm>
#include <regex>
#include <string>

// Time:
// Space:

class Solution {
public:
  static std::string reverseWords(std::string str) {
    auto begin = str.begin();
    std::string::iterator end;
    do {
      end = std::find(begin, str.end(), ' ');
      std::reverse(begin, end);
      begin = std::next(end);
    } while (end != str.end());
    return str;
  }
};
