#pragma once

#include <stack>
#include <string>

// Time: O(N)
// Space: O(1)

namespace stack {

// Time: O(N)
// Space: O(N)
class Solution {
public:
  static bool checkValidString(std::string s) {
    std::stack<int> openBrackets, asterisks;
    for (int i = 0; i < std::ssize(s); ++i) {
      if (s[i] == '(') {
        openBrackets.push(i);
      } else if (s[i] == '*') {
        asterisks.push(i);
      } else if (s[i] == ')') {
        if (!openBrackets.empty()) {
          openBrackets.pop();
        } else if (!asterisks.empty()) {
          asterisks.pop();
        } else {
          return false;
        }
      } else {
        throw;
      }
    }

    while (!openBrackets.empty() && !asterisks.empty()) {
      if (asterisks.top() < openBrackets.top()) {
        return false;
      }
      openBrackets.pop();
      asterisks.pop();
    }
    return openBrackets.empty();
  }
};

} // namespace stack

namespace opt {

// Time: O(N)
// Space: O(1)
class Solution {
public:
  static bool checkValidString(std::string s) {
    int open = 0, close = 0;
    for (auto c : s) {
      if (c == '(') {
        ++open, ++close;
      } else if (c == ')') {
        --open, --close;
      } else if (c == '*') {
        --open, ++close;
      } else {
        throw;
      }
      open = std::max(0, open);
      if (close < 0) {
        return false;
      }
    }
    return open == 0;
  }
};

} // namespace opt
