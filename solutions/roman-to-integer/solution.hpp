#pragma once

#include <string>
#include <unordered_map>

class Solution {
private:
  static const inline std::unordered_map<char, int> symbols{
      {'I', 1},   {'V', 5},   {'X', 10},   {'L', 50},
      {'C', 100}, {'D', 500}, {'M', 1000},
  };

public:
  static int romanToInt(std::string s) {
    int num = 0;
    for (size_t i = 0; i < s.size(); ++i) {
      if (i + 1 != s.size() && symbols.at(s[i]) < symbols.at(s[i + 1])) {
        num -= symbols.at(s[i]);
      } else {
        num += symbols.at(s[i]);
      }
    }
    return num;
  }
};
