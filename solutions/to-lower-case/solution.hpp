#pragma once

#include <algorithm>
#include <string>

// Time:
// Space:

class Solution {
public:
  static std::string toLowerCase(std::string s) {
    std::transform(s.begin(), s.end(), s.begin(),
                   [](unsigned char c) { return std::tolower(c); });
    return s;
  }
};
