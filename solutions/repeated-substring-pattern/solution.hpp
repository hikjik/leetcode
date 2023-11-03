#pragma once

#include <string>

// Time:
// Space:

class Solution {
public:
  static bool repeatedSubstringPattern(std::string s) {
    return (s + s).find(s, 1) < s.size();
  }
};
