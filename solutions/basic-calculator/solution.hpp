#pragma once

#include <stack>
#include <string>

class Solution {
public:
  static int calculate(std::string s) {
    int ans = 0;
    int sign = 1;
    int number = 0;
    std::stack<int> stack{{sign}};
    for (auto c : s) {
      if (std::isdigit(c)) {
        number = number * 10 + (c - '0');
      } else if (c == '(') {
        stack.push(sign);
      } else if (c == ')') {
        stack.pop();
      } else if (c == '+' || c == '-') {
        ans += sign * number;
        number = 0;
        sign = stack.top() * (c == '+' ? 1 : -1);
      }
    }
    return ans + number * sign;
  }
};
