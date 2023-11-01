#pragma once

#include <string>
#include <vector>

/*
  2011. Final Value of Variable After Performing Operations
  https://leetcode.com/problems/final-value-of-variable-after-performing-operations/
  Difficulty: Easy
  Tags: Array, String, Simulation
  Time:
  Space:
*/

class Solution {
public:
  static int
  finalValueAfterOperations(const std::vector<std::string> &operations) {
    int x = 0;
    for (const auto &op : operations) {
      x += op[1] == '+' ? 1 : -1;
    }
    return x;
  }
};
