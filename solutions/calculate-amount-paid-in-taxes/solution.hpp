#pragma once

#include <vector>

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
