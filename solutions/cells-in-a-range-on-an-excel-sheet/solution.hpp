#pragma once

#include <string>
#include <vector>

// Time:
// Space:

class Solution {
public:
  static std::vector<std::string> cellsInRange(std::string s) {
    std::vector<std::string> ans;
    for (char c = s[0]; c <= s[3]; ++c) {
      for (char r = s[1]; r <= s[4]; ++r) {
        ans.push_back({c, r});
      }
    }
    return ans;
  }
};
