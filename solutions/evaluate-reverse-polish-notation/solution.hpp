#pragma once

#include <functional>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

class Solution {
public:
  static int evalRPN(const std::vector<std::string> &tokens) {
    const std::unordered_map<std::string, std::function<int(int, int)>> ops{
        {"+", std::plus<int>()},
        {"-", std::minus<int>()},
        {"*", std::multiplies<int>()},
        {"/", std::divides<int>()}};

    std::stack<int> stack;
    for (const auto &token : tokens) {
      if (ops.count(token)) {
        int b = stack.top();
        stack.pop();
        int a = stack.top();
        stack.pop();
        stack.push(ops.at(token)(a, b));
      } else {
        stack.push(std::stoi(token));
      }
    }
    return stack.top();
  }
};