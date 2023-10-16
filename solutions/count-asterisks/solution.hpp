#pragma once

#include <string>

class Solution {
public:
  static int countAsterisks(std::string s) {
    int verticals_bars = 0, asterisks = 0;
    for (auto c : s) {
      if (c == '|') {
        ++verticals_bars;
      } else if (c == '*' && verticals_bars % 2 == 0) {
        ++asterisks;
      }
    }
    return asterisks;
  }
};
