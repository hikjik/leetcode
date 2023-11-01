#pragma once

/*
  2520. Count the Digits That Divide a Number
  https://leetcode.com/problems/count-the-digits-that-divide-a-number/
  Difficulty: Easy
  Tags: Math
  Time:
  Space:
*/

class Solution {
public:
  static int countDigits(int num) {
    int cnt = 0;
    for (int i = num; i; i /= 10) {
      if (int digit = i % 10; num % digit == 0) {
        ++cnt;
      }
    }
    return cnt;
  }
};
