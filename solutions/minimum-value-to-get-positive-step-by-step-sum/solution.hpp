#pragma once

#include <vector>

/*
  1413. Minimum Value to Get Positive Step by Step Sum
  https://leetcode.com/problems/minimum-value-to-get-positive-step-by-step-sum/
  Difficulty: Easy
  Tags: Array, Prefix Sum
  Time:
  Space:
*/

class Solution {
public:
  static int minStartValue(const std::vector<int> &nums) {
    int ans = 1;
    for (int sum = 0; auto a : nums) {
      sum += a;
      ans = std::max(ans, 1 - sum);
    }
    return ans;
  }
};
