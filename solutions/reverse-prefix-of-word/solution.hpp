#pragma once

#include <algorithm>
#include <string>

class Solution {
public:
  static std::string reversePrefix(std::string word, char ch) {
    if (auto pos = word.find(ch); pos != std::string::npos) {
      std::reverse(word.begin(), word.begin() + pos + 1);
    }
    return word;
  }
};
