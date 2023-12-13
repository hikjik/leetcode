#pragma once

#include <string>

// Time: O(N)
// Space: O(1)

class Solution {
public:
  static int minAddToMakeValid(std::string s) {
    int opening = 0, closing = 0;
    for (auto c : s) {
      if (c == ')') {
        closing ? --closing : ++opening;
      } else {
        ++closing;
      }
    }
    return opening + closing;
  }
};
