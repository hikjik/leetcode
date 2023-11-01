#pragma once

/*
  2180. Count Integers With Even Digit Sum
  https://leetcode.com/problems/count-integers-with-even-digit-sum/
  Difficulty: Easy
  Tags: Math, Simulation
  Time:
  Space:
*/

class Solution {
public:
  static int countEven(int num) { return (num - digitSum(num) % 2) / 2; }

private:
  static int digitSum(int num) {
    int sum = 0;
    for (int i = num; i; i /= 10) {
      sum += i % 10;
    }
    return sum;
  }
};
