#pragma once

/*
  172. Factorial Trailing Zeroes
  https://leetcode.com/problems/factorial-trailing-zeroes/
  Difficulty: Medium
  Tags: Math
  Time:
  Space:
*/

class Solution {
public:
  static int trailingZeroes(int n) {
    int ans = 0;
    while (n) {
      n /= 5;
      ans += n;
    }
    return ans;
  }
};
