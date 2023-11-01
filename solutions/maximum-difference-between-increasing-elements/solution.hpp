#pragma once

#include <climits>
#include <vector>

/*
  2016. Maximum Difference Between Increasing Elements
  https://leetcode.com/problems/maximum-difference-between-increasing-elements/
  Difficulty: Easy
  Tags: Array
  Time:
  Space:
*/

class Solution {
public:
  static int maximumDifference(const std::vector<int> &nums) {
    int ans = -1;
    for (int min = INT_MAX; auto a : nums) {
      if (a > min) {
        ans = std::max(ans, a - min);
      }
      min = std::min(min, a);
    }
    return ans;
  }
};
