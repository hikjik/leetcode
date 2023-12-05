#pragma once

#include <string>

// Time: O(N+M)
// Space: O(1)

class Solution {
public:
  static bool isSubsequence(std::string s, std::string t) {
    for (size_t pos = 0; auto c : s) {
      pos = t.find(c, pos);
      if (pos == std::string::npos) {
        return false;
      }
      ++pos;
    }
    return true;
  }
};
