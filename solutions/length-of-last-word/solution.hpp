#pragma once

#include <string>

class Solution {
public:
  static int lengthOfLastWord(std::string s) {
    int i = s.size() - 1;
    while (i >= 0 && std::isspace(s[i])) {
      --i;
    }
    int j = i;
    while (j >= 0 && !std::isspace(s[j])) {
      --j;
    }
    return i - j;
  }
};
