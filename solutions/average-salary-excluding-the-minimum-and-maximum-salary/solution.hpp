#pragma once

#include <algorithm>
#include <limits>
#include <vector>

class Solution {
public:
  static double average(const std::vector<int> &salaries) {
    int max = std::numeric_limits<int>::min();
    int min = std::numeric_limits<int>::max();
    int sum = 0;
    for (auto salary : salaries) {
      max = std::max(max, salary);
      min = std::min(min, salary);
      sum += salary;
    }

    return (sum - min - max) * 1.0 / (salaries.size() - 2);
  }
};
