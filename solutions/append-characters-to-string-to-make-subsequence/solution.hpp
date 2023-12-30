#pragma once

#include <string>

// Time: O(N+M)
// Space: O(1)

class Solution {
public:
  static int appendCharacters(std::string s, std::string t) {
    int i = 0;
    for (auto c : s) {
      if (i < std::ssize(t) && c == t[i]) {
        ++i;
      }
    }
    return t.size() - i;
  }
};
