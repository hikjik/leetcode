#pragma once

#include <algorithm>
#include <stack>
#include <string>

// Time: O(N)
// Space: O(N)

namespace stack {

// Time: O(N)
// Space: O(N)
class Solution {
public:
  static int longestValidParentheses(std::string s) {
    std::stack<int> stack{{-1}};
    int max_length = 0;
    for (int i = 0; i < std::ssize(s); ++i) {
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

} // namespace stack

namespace dp {

// Time: O(N)
// Space: O(N)
class Solution {
public:
  static int longestValidParentheses(std::string s) {
    s.insert(0, ")");
    std::vector<int> dp(s.size());
    for (int i = 1; i < std::ssize(s); ++i) {
      if (s[i] == ')' && s[i - dp[i - 1] - 1] == '(') {
        dp[i] = 2 + dp[i - 1] + dp[i - dp[i - 1] - 2];
      }
    }
    return *std::max_element(dp.begin(), dp.end());
  }
};

} // namespace dp
