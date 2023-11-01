#pragma once

#include <algorithm>
#include <vector>

/*
  2824. Count Pairs Whose Sum is Less than Target
  https://leetcode.com/problems/count-pairs-whose-sum-is-less-than-target/
  Difficulty: Easy
  Tags: Array, Two Pointers, Sorting
  Time:
  Space:
*/

class Solution {
public:
  static int countPairs(std::vector<int> nums, int target) {
    std::sort(nums.begin(), nums.end());

    int cnt = 0;
    for (auto l = nums.begin(), r = --nums.end(); l != r;) {
      if (*l + *r < target) {
        cnt += r - l;
        ++l;
      } else {
        --r;
      }
    }
    return cnt;
  }
};
