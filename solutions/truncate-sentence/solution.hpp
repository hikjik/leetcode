#pragma once

#include <sstream>
#include <string>

class Solution {
public:
  static std::string truncateSentence(std::string s, int k) {
    std::string ans;
    std::istringstream stream(s);
    for (std::string word; stream >> word && k--;) {
      ans += word + (k ? " " : "");
    }
    return ans;
  }
};
