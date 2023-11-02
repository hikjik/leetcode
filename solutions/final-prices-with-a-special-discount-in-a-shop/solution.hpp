#pragma once

#include <stack>
#include <vector>

// Time:
// Space:

class Solution {
public:
  static std::vector<int> finalPrices(const std::vector<int> &prices) {
    std::vector<int> final(prices);
    std::stack<int> stack;
    for (int i = prices.size() - 1; i >= 0; --i) {
      while (!stack.empty() && stack.top() > prices[i]) {
        stack.pop();
      }
      final[i] -= stack.empty() ? 0 : stack.top();
      stack.push(prices[i]);
    }
    return final;
  }
};
