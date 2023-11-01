#pragma once

/*
  1837. Sum of Digits in Base K
  https://leetcode.com/problems/sum-of-digits-in-base-k/
  Difficulty: Easy
  Tags: Math
  Time:
  Space:
*/

class Solution {
public:
  static int sumBase(int n, int k) {
    int sum = 0;
    for (int i = n; i; i /= k) {
      sum += i % k;
    }
    return sum;
  }
};
