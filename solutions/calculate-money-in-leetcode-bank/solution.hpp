#pragma once

/*
  1716. Calculate Money in Leetcode Bank
  https://leetcode.com/problems/calculate-money-in-leetcode-bank/
  Difficulty: Easy
  Tags: Math
  Time:
  Space:
*/

class Solution {
public:
  static int totalMoney(int n) {
    const int q = n / 7, r = n % 7;
    return q * sum(7) + 7 * sum(q - 1) + q * r + sum(r);
  }

private:
  static int sum(int n) { return (n + 1) * n / 2; }
};
