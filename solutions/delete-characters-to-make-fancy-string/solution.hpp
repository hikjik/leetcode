#pragma once

#include <string>

class Solution {
public:
  static std::string makeFancyString(std::string s) {
    std::string ans;
    for (size_t i = 0; i < s.size(); ++i) {
      if (i < 2 || s[i] != s[i - 1] || s[i] != s[i - 2]) {
        ans.push_back(s[i]);
      }
    }
    return ans;
  }
};
