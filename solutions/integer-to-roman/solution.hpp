#pragma once

#include <string>
#include <vector>

class Solution {
public:
  static std::string intToRoman(int n) {
    static const std::vector<std::pair<std::string, int>> symbols{
        {"M", 1000}, {"CM", 900}, {"D", 500}, {"CD", 400}, {"C", 100},
        {"XC", 90},  {"L", 50},   {"XL", 40}, {"X", 10},   {"IX", 9},
        {"V", 5},    {"IV", 4},   {"I", 1},
    };
    std::string roman;
    for (const auto &[s, k] : symbols) {
      while (n >= k) {
        roman += s;
        n -= k;
      }
    }
    return roman;
  }
};
