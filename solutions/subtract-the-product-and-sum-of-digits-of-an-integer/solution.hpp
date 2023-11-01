#pragma once

/*
  1281. Subtract the Product and Sum of Digits of an Integer
  https://leetcode.com/problems/subtract-the-product-and-sum-of-digits-of-an-integer/
  Difficulty: Easy
  Tags: Math
  Time:
  Space:
*/

class Solution {
public:
  static int subtractProductAndSum(int n) {
    int product = 1;
    int sum = 0;
    while (n) {
      const auto r = n % 10;
      n /= 10;
      product *= r;
      sum += r;
    }
    return product - sum;
  }
};
