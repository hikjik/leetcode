#pragma once

#include <functional>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

// Time: O(N)
// Space: O(N)

class Solution {
public:
  static int evalRPN(const std::vector<std::string> &tokens) {
    static const std::unordered_map<std::string, std::function<int(int, int)>>
        ops{{"+", std::plus<int>()},
            {"-", std::minus<int>()},
            {"*", std::multiplies<int>()},
            {"/", std::divides<int>()}};

    std::stack<int> stack;
    for (const auto &token : tokens) {
      if (ops.contains(token)) {
        const auto b = stack.top();
        stack.pop();
        const auto a = stack.top();
        stack.pop();
        stack.push(ops.at(token)(a, b));
      } else {
        stack.push(std::stoi(token));
      }
    }
    return stack.top();
  }
};
