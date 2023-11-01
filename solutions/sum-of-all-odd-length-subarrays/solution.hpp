#pragma once

#include <vector>

/*
  1588. Sum of All Odd Length Subarrays
  https://leetcode.com/problems/sum-of-all-odd-length-subarrays/
  Difficulty: Easy
  Tags: Array, Math, Prefix Sum
  Time:
  Space:
*/

class Solution {
public:
  static int sumOddLengthSubarrays(const std::vector<int> &arr) {
    int n = arr.size();
    int sum = 0;

    for (int i = 0; i < n; ++i) {
      int total = (i + 1) * (arr.size() - i);
      int total_odd = (total + 1) / 2;
      sum += total_odd * arr[i];
    }
    return sum;
  }
};
