#pragma once

#include <string>

// Time:
// Space:

class Solution {
public:
  static int calculate(std::string s) {
    int result = 0;
    int left = 0, right = 0;
    char op = '+';
    for (size_t i = 0; i < s.length(); ++i) {
      if (std::isdigit(s[i])) {
        right *= 10;
        right += s[i] - '0';
      }

      if (!std::isdigit(s[i]) && !std::isspace(s[i]) || i + 1 == s.length()) {
        if (op == '+' || op == '-') {
          result += left;
          left = op == '+' ? right : -right;
        } else if (op == '*') {
          left *= right;
        } else if (op == '/') {
          left /= right;
        }
        op = s[i];
        right = 0;
      }
    }
    return result + left;
  }
};
