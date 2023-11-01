#pragma once

#include <vector>

/*
  1920. Build Array from Permutation
  https://leetcode.com/problems/build-array-from-permutation/
  Difficulty: Easy
  Tags: Array, Simulation
  Time:
  Space:
*/

class Solution {
public:
  static std::vector<int> buildArray(std::vector<int> nums) {
    const int n = nums.size();
    for (int i = 0; i < n; ++i) {
      nums[i] += n * (nums[nums[i]] % n);
    }
    for (int i = 0; i < n; ++i) {
      nums[i] /= n;
    }
    return nums;
  }
};
