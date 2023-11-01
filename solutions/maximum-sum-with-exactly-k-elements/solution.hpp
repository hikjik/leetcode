#pragma once

#include <algorithm>
#include <vector>

/*
  2656. Maximum Sum With Exactly K Elements
  https://leetcode.com/problems/maximum-sum-with-exactly-k-elements/
  Difficulty: Easy
  Tags: Array, Greedy
  Time:
  Space:
*/

class Solution {
public:
  static int maximizeSum(const std::vector<int> &nums, int k) {
    return *std::max_element(nums.begin(), nums.end()) * k + (k - 1) * k / 2;
  }
};
