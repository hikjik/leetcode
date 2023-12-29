#pragma once

#include <string>

// Time: O(N)
// Space: O(N)

class Solution {
public:
  static std::string maximumBinaryString(std::string s) {
    if (auto p = s.find('0'); p != std::string::npos) {
      const auto k = std::ranges::count(s, '0');
      std::ranges::fill(s, '1');
      s[k + p - 1] = '0';
    }
    return s;
  }
};
