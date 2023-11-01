#pragma once

/*
  258. Add Digits
  https://leetcode.com/problems/add-digits/
  Difficulty: Easy
  Tags: Math, Simulation, Number Theory
  Time:
  Space:
*/

class Solution {
public:
  static int addDigits(int num) { return (num - 1) % 9 + 1; };
};
