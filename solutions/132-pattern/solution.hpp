#pragma once

#include <climits>
#include <stack>
#include <vector>

/*
  456. 132 Pattern
  https://leetcode.com/problems/132-pattern/
  Difficulty: Medium
  Tags: Array, Binary Search, Stack, Monotonic Stack, Ordered Set
  Time:
  Space:
*/

class Solution {
public:
  static bool find132pattern(const std::vector<int> &nums) {
    int middle = INT_MIN;
    std::stack<int> stack;

    for (int i = nums.size() - 1; i >= 0; --i) {
      if (nums[i] < middle) {
        return true;
      }

      while (!stack.empty() && stack.top() < nums[i]) {
        middle = stack.top();
        stack.pop();
      }

      stack.push(nums[i]);
    }

    return false;
  }
};
