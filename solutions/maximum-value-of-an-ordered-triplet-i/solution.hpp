#pragma once

#include <vector>

/*
  2873. Maximum Value of an Ordered Triplet I
  https://leetcode.com/problems/maximum-value-of-an-ordered-triplet-i/
  Difficulty: Easy
  Tags: Array
  Time:
  Space:
*/

class Solution {
public:
  static long long maximumTripletValue(const std::vector<int> &nums) {
    long long max_triplet_value = 0;
    int max_num = 0, max_diff = 0;
    for (auto num : nums) {
      max_triplet_value = std::max(max_triplet_value, num * 1LL * max_diff);
      max_diff = std::max(max_diff, max_num - num);
      max_num = std::max(max_num, num);
    }
    return max_triplet_value;
  }
};
