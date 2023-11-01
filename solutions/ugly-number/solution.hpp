#pragma once

/*
  263. Ugly Number
  https://leetcode.com/problems/ugly-number/
  Difficulty: Easy
  Tags: Math
  Time:
  Space:
*/

class Solution {
public:
  static bool isUgly(int n) {
    if (n < 1) {
      return false;
    }

    for (auto d : {2, 3, 5}) {
      while (n % d == 0) {
        n /= d;
      }
    }
    return n == 1;
  }
};
