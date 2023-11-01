#pragma once

#include <vector>

/*
  2366. Minimum Replacements to Sort the Array
  https://leetcode.com/problems/minimum-replacements-to-sort-the-array/
  Difficulty: Hard
  Tags: Array, Math, Greedy
  Time:
  Space:
*/

class Solution {
public:
  static long long minimumReplacement(const std::vector<int> &nums) {
    long long operations = 0;
    int bound = nums.back();
    for (int i = nums.size() - 2; i >= 0; --i) {
      const auto pieces_count = (nums[i] + bound - 1) / bound;
      operations += pieces_count - 1;
      bound = nums[i] / pieces_count;
    }
    return operations;
  }
};
