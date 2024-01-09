#pragma once

#include <string>

// Time: O(N)
// Space: O(N)

class Solution {
public:
  static std::string parseTernary(std::string expression) {
    std::string stack;
    for (int i = expression.size() - 1; i >= 0; --i) {
      if (!stack.empty() && stack.back() == '?') {
        const auto n = stack.size();
        if (expression[i] == 'T') {
          stack[n - 4] = stack[n - 2];
        }
        stack.resize(n - 3);
      } else {
        stack.push_back(expression[i]);
      }
    }
    return stack;
  }
};
