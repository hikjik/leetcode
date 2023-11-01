#pragma once

#include <climits>
#include <vector>

/*
  334. Increasing Triplet Subsequence
  https://leetcode.com/problems/increasing-triplet-subsequence/
  Difficulty: Medium
  Tags: Array, Greedy
  Time:
  Space:
*/

class Solution {
public:
  static bool increasingTriplet(const std::vector<int> &nums) {
    int first = INT_MAX, second = INT_MAX;
    for (auto num : nums) {
      if (num <= first) {
        first = num;
      } else if (num <= second) {
        second = num;
      } else {
        return true;
      }
    }
    return false;
  }
};
