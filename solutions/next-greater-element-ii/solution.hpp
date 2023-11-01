#pragma once

#include <stack>
#include <vector>

/*
  503. Next Greater Element II
  https://leetcode.com/problems/next-greater-element-ii/
  Difficulty: Medium
  Tags: Array, Stack, Monotonic Stack
  Time:
  Space:
*/

class Solution {
public:
  static std::vector<int> nextGreaterElements(const std::vector<int> &nums) {
    int n = nums.size();
    std::stack<std::pair<int, int>> stack;
    std::vector<int> greater_elements(n, -1);
    for (int i = 0; i < 2 * n + 1; ++i) {
      int num = nums[i % n];
      while (!stack.empty() && stack.top().first < num) {
        greater_elements[stack.top().second] = num;
        stack.pop();
      }
      if (i < n) {
        stack.emplace(num, i);
      }
    }
    return greater_elements;
  }
};