#pragma once

#include <vector>

/*
  1283. Find the Smallest Divisor Given a Threshold
  https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/
  Difficulty: Medium
  Tags: Array, Binary Search
  Time:
  Space:
*/

class Solution {
public:
  static int smallestDivisor(const std::vector<int> &nums, int threshold) {
    int left = 1, right = 1e6;
    while (left < right) {
      const auto middle = left + (right - left) / 2;
      long long sum = 0;
      for (auto num : nums) {
        sum += (num + middle - 1) / middle;
      }
      sum > threshold ? left = middle + 1 : right = middle;
    }
    return left;
  }
};
