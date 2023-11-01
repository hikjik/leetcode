#pragma once

#include <numeric>
#include <vector>

/*
  1991. Find the Middle Index in Array
  https://leetcode.com/problems/find-the-middle-index-in-array/
  Difficulty: Easy
  Tags: Array, Prefix Sum
  Time:
  Space:
*/

class Solution {
public:
  static int findMiddleIndex(const std::vector<int> &nums) {
    auto left = 0, right = std::accumulate(nums.begin(), nums.end(), 0);
    for (int i = 0; i < std::ssize(nums); ++i) {
      right -= nums[i];
      if (left == right) {
        return i;
      }
      left += nums[i];
    }
    return -1;
  }
};
