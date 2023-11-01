#pragma once

/*
  2544. Alternating Digit Sum
  https://leetcode.com/problems/alternating-digit-sum/
  Difficulty: Easy
  Tags: Math
  Time:
  Space:
*/

class Solution {
public:
  static int alternateDigitSum(int n) {
    int sum = 0, sign = 1;
    for (auto i = n; i; i /= 10) {
      sign *= -1;
      sum += sign * i % 10;
    }
    return sign * sum;
  }
};
