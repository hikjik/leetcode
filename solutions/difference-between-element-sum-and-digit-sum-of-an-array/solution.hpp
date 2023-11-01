#pragma once

#include <vector>

/*
  2535. Difference Between Element Sum and Digit Sum of an Array
  https://leetcode.com/problems/difference-between-element-sum-and-digit-sum-of-an-array/
  Difficulty: Easy
  Tags: Array, Math
  Time:
  Space:
*/

class Solution {
public:
  static int differenceOfSum(const std::vector<int> &nums) {
    int sum = 0, digits_sum = 0;
    for (auto num : nums) {
      sum += num;
      while (num) {
        digits_sum += num % 10;
        num /= 10;
      }
    }
    return abs(sum - digits_sum);
  }
};