#pragma once

#include <algorithm>
#include <vector>

/*
  2798. Number of Employees Who Met the Target
  https://leetcode.com/problems/number-of-employees-who-met-the-target/
  Difficulty: Easy
  Tags: Array, Enumeration
  Time:
  Space:
*/

class Solution {
public:
  static int numberOfEmployeesWhoMetTarget(const std::vector<int> &hours,
                                           int target) {
    return std::count_if(hours.begin(), hours.end(),
                         [target](int h) { return h >= target; });
  }
};
