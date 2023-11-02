#pragma once

#include <string>

// Time:
// Space:

class Solution {
public:
  static int maxDepth(std::string s) {
    int max_depth = 0;
    for (int depth = 0; auto c : s) {
      if (c == '(') {
        max_depth = std::max(max_depth, ++depth);
      } else if (c == ')') {
        --depth;
      }
    }
    return max_depth;
  }
};
