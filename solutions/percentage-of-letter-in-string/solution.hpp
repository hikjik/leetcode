#pragma once

#include <string>

// Time:
// Space:

class Solution {
public:
  static int percentageLetter(std::string s, char letter) {
    return 100 * std::count(s.begin(), s.end(), letter) / s.size();
  }
};
