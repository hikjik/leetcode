#pragma once

#include <stack>
#include <string>

// Time: O(N)
// Space: O(N)

class Solution {
public:
  static int scoreOfParentheses(std::string s) {
    std::stack<int> stack;
    int ans = 0;
    for (auto c : s) {
      if (c == '(') {
        stack.push(std::exchange(ans, 0));
      } else {
        ans = stack.top() + std::max(2 * ans, 1);
        stack.pop();
      }
    }
    return ans;
  }
};
