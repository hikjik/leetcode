#pragma once

#include <cmath>

/*
  633. Sum of Square Numbers
  https://leetcode.com/problems/sum-of-square-numbers/
  Difficulty: Medium
  Tags: Math, Two Pointers, Binary Search
  Time:
  Space:
*/

class Solution {
public:
  static bool judgeSquareSum(int c) {
    long long left = 0, right = std::sqrt(c);
    while (left <= right) {
      const auto sum = left * left + right * right;
      if (sum == c) {
        return true;
      }
      if (sum > c) {
        right--;
      } else {
        left++;
      }
    }
    return false;
  }
};
