#pragma once

#include <string>

// Time:
// Space:

class Solution {
public:
  static bool canBeEqual(std::string s1, std::string s2) {
    for (int i : {0, 1}) {
      if (s1[i] != s2[i]) {
        std::swap(s1[i], s1[i + 2]);
      }
    }
    return s1 == s2;
  }
};
