#pragma once

#include <algorithm>
#include <stack>
#include <string>

class Solution {
public:
  static int longestValidParentheses(std::string s) {
    std::stack<size_t> stack;
    stack.push(-1);
    size_t max_length = 0;
    for (size_t i = 0; i < s.size(); ++i) {
      if (s[i] == '(') {
        stack.push(i);
      } else {
        stack.pop();
        if (stack.empty()) {
          stack.push(i);
        } else {
          max_length = std::max(max_length, i - stack.top());
        }
      }
    }
    return max_length;
  }
};
