#pragma once

#include <stack>
#include <string>

/*
  20. Valid Parentheses
  https://leetcode.com/problems/valid-parentheses/
  Difficulty: Easy
  Tags: String, Stack
  Time:
  Space:
*/

class Solution {
public:
  static bool isValid(std::string s) {
    std::stack<char> stack;
    for (auto c : s) {
      if (isOpen(c)) {
        stack.push(c);
      } else {
        if (stack.empty() || !isSameType(stack.top(), c)) {
          return false;
        }
        stack.pop();
      }
    }
    return stack.empty();
  }

private:
  static bool isOpen(char c) { return c == '[' || c == '{' || c == '('; }

  static bool isSameType(char open, char close) {
    return (open == '{' && close == '}') || (open == '(' && close == ')') ||
           (open == '[' && close == ']');
  }
};
