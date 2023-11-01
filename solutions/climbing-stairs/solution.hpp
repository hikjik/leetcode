#pragma once

/*
  70. Climbing Stairs
  https://leetcode.com/problems/climbing-stairs/
  Difficulty: Easy
  Tags: Math, Dynamic Programming, Memoization
  Time:
  Space:
*/

class Solution {
public:
  static int climbStairs(int n) {
    int a = 1;
    int b = 1;
    for (int i = 1; i < n; ++i) {
      int sum = a + b;
      a = b;
      b = sum;
    }
    return b;
  }
};