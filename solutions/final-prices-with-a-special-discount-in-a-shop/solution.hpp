#pragma once

#include <stack>
#include <vector>

/*
  1475. Final Prices With a Special Discount in a Shop
  https://leetcode.com/problems/final-prices-with-a-special-discount-in-a-shop/
  Difficulty: Easy
  Tags: Array, Stack, Monotonic Stack
  Time:
  Space:
*/

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
