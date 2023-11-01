#pragma once

#include <stack>
#include <vector>

/*
  739. Daily Temperatures
  https://leetcode.com/problems/daily-temperatures/
  Difficulty: Medium
  Tags: Array, Stack, Monotonic Stack
  Time:
  Space:
*/

class Solution {
public:
  static std::vector<int>
  dailyTemperatures(const std::vector<int> &temperatures) {
    int n = temperatures.size();
    std::stack<int> stack;
    std::vector<int> days(n, 0);
    for (int i = 0; i < n; ++i) {
      while (!stack.empty() && temperatures[stack.top()] < temperatures[i]) {
        days[stack.top()] = i - stack.top();
        stack.pop();
      }
      stack.push(i);
    }
    return days;
  }
};
