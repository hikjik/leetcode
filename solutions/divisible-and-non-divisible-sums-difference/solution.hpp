#pragma once

/*
  2894. Divisible and Non-divisible Sums Difference
  https://leetcode.com/problems/divisible-and-non-divisible-sums-difference/
  Difficulty: Easy
  Tags: Math
  Time:
  Space:
*/

class Solution {
public:
  static int differenceOfSums(int n, int m) {
    return (n * (n + 1)) / 2 - (m + n / m * m) * (n / m);
  }
};
