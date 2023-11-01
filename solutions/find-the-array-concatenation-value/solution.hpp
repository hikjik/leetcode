#pragma once

#include <cmath>
#include <vector>

/*
  2562. Find the Array Concatenation Value
  https://leetcode.com/problems/find-the-array-concatenation-value/
  Difficulty: Easy
  Tags: Array, Two Pointers, Simulation
  Time:
  Space:
*/

class Solution {
public:
  static long long findTheArrayConcVal(const std::vector<int> &nums) {
    const int n = nums.size();
    auto value = 0LL;
    for (int i = 0; i < n / 2; ++i) {
      const int digits = std::log10(nums[n - i - 1]) + 1;
      value += nums[i] * std::pow(10, digits) + nums[n - i - 1];
    }
    if (n & 1) {
      value += nums[n / 2];
    }
    return value;
  }
};
