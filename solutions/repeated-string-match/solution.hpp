#pragma once

#include <string>

// Time:
// Space:

class Solution {
public:
  static int repeatedStringMatch(std::string a, std::string b) {
    int n = (b.size() + a.size() - 1) / a.size();

    std::string c;
    for (int i = 0; i <= n; ++i) {
      c += a;
    }

    if (auto i = c.find(b); i != std::string::npos) {
      return i + b.size() + a.size() <= c.size() ? n : n + 1;
    }
    return -1;
  }
};
