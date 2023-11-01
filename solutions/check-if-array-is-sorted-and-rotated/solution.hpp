#pragma once

#include <vector>

/*
  1752. Check if Array Is Sorted and Rotated
  https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/
  Difficulty: Easy
  Tags: Array
  Time:
  Space:
*/

class Solution {
public:
  static bool check(const std::vector<int> &nums) {
    int n = nums.size();

    int cnt = 0;
    for (int i = 0; i < n; ++i) {
      if (nums[i] > nums[(i + 1) % n]) {
        cnt++;
      }
    }
    return cnt < 2;
  }
};