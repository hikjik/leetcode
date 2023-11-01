#pragma once

#include <vector>

/*
  2303. Calculate Amount Paid in Taxes
  https://leetcode.com/problems/calculate-amount-paid-in-taxes/
  Difficulty: Easy
  Tags: Array, Simulation
  Time:
  Space:
*/

class Solution {
public:
  static double calculateTax(const std::vector<std::vector<int>> &brackets,
                             int income) {
    int taxes = 0, prev_upper = 0;
    for (const auto &bracket : brackets) {
      const auto upper = std::min(income, bracket[0]);
      const auto percent = bracket[1];
      taxes += (upper - prev_upper) * percent;
      prev_upper = upper;
    }
    return taxes / 100.0;
  }
};
