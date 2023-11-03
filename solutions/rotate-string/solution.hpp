#pragma once

#include <string>

// Time:
// Space:

class Solution {
public:
  static bool rotateString(std::string s, std::string goal) {
    return s.size() == goal.size() && (s + s).find(goal) != std::string::npos;
  }
};
