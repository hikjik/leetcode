#pragma once

#include <string>

// Time:
// Space:

class Solution {
public:
  static int findLUSlength(std::string a, std::string b) {
    return a == b ? -1 : std::max(a.size(), b.size());
  }
};
