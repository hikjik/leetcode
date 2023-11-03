#pragma once

#include <string>

// Time:
// Space:

class Solution {
public:
  static int minLength(std::string s) {
    std::string stack;
    for (auto c : s) {
      if (!stack.empty() && (c == 'B' && stack.back() == 'A' ||
                             c == 'D' && stack.back() == 'C')) {
        stack.pop_back();
      } else {
        stack.push_back(c);
      }
    }
    return stack.size();
  }
};
