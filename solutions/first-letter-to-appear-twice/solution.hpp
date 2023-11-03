#pragma once

#include <string>
#include <vector>

// Time:
// Space:

class Solution {
public:
  static char repeatedCharacter(std::string s) {
    std::vector<int> counter(128);
    for (auto c : s) {
      if (counter[c]++) {
        return c;
      }
    }
    throw;
  }
};
