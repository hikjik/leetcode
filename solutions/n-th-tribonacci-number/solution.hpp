#pragma once

/*
  1137. N-th Tribonacci Number
  https://leetcode.com/problems/n-th-tribonacci-number/
  Difficulty: Easy
  Tags: Math, Dynamic Programming, Memoization
  Time:
  Space:
*/

class Solution {
public:
  static int tribonacci(int n) {
    if (n < 3) {
      return (n + 1) / 2;
    }

    int a = 0, b = 1, c = 1;
    for (int i = 2; i < n; ++i) {
      int sum = a + b + c;
      a = b;
      b = c;
      c = sum;
    }

    return c;
  }
};