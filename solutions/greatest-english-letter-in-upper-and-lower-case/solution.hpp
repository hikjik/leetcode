#pragma once

#include <string>
#include <vector>

class Solution {
public:
  static std::string greatestLetter(std::string s) {
    std::vector<int> count(128);
    for (auto c : s) {
      ++count[c];
    }

    for (char c = 'Z'; c >= 'A'; --c) {
      if (count[c] && count[c - 'A' + 'a']) {
        return std::string{c};
      }
    }
    return "";
  }
};
