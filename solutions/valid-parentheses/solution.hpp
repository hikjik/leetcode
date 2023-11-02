#pragma once

#include <stack>
#include <string>

// Time: O(N)
// Space: O(N)

class Solution {
public:
  static bool isValid(std::string s) {
    std::stack<char> stack;
    for (auto c : s) {
      if (c == '(') {
        stack.push(')');
      } else if (c == '[') {
        stack.push(']');
      } else if (c == '{') {
        stack.push('}');
      } else {
        if (stack.empty() || stack.top() != c) {
          return false;
        }
        stack.pop();
      }
    }
    return stack.empty();
  }
};
