#pragma once

#include <vector>

/*
  946. Validate Stack Sequences
  https://leetcode.com/problems/validate-stack-sequences/
  Difficulty: Medium
  Tags: Array, Stack, Simulation
  Time:
  Space:
*/

class Solution {
public:
  static bool validateStackSequences(const std::vector<int> &pushed,
                                     const std::vector<int> &popped) {
    std::vector<int> stack;
    size_t i = 0;
    for (auto a : pushed) {
      stack.push_back(a);
      while (!stack.empty() && stack.back() == popped[i]) {
        stack.pop_back();
        i++;
      }
    }
    return stack.empty();
  }
};
