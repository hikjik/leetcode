#pragma once

#include <utility>

/*
  2169. Count Operations to Obtain Zero
  https://leetcode.com/problems/count-operations-to-obtain-zero/
  Difficulty: Easy
  Tags: Math, Simulation
  Time:
  Space:
*/

class Solution {
public:
  static int countOperations(int num1, int num2) {
    int ops = 0;
    while (num1 && num2) {
      if (num1 < num2) {
        std::swap(num1, num2);
      }
      ops += num1 / num2;
      num1 %= num2;
    }
    return ops;
  }
};
