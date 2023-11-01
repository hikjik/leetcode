#pragma once

#include <algorithm>
#include <limits>
#include <vector>

/*
  1491. Average Salary Excluding the Minimum and Maximum Salary
  https://leetcode.com/problems/average-salary-excluding-the-minimum-and-maximum-salary/
  Difficulty: Easy
  Tags: Array, Sorting
  Time:
  Space:
*/

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
