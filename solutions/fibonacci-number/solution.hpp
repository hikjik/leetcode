#pragma once

/*
  509. Fibonacci Number
  https://leetcode.com/problems/fibonacci-number/
  Difficulty: Easy
  Tags: Math, Dynamic Programming, Recursion, Memoization
  Time:
  Space:
*/

class Solution {
public:
  static int fib(int n) {
    if (n < 2) {
      return n;
    }

    int a = 0, b = 1;
    for (int i = 1; i < n; ++i) {
      int c = a;
      a = b;
      b += c;
    }

    return b;
  }
};