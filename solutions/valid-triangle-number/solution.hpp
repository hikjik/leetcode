#pragma once

#include <algorithm>
#include <vector>

/*
  611. Valid Triangle Number
  https://leetcode.com/problems/valid-triangle-number/
  Difficulty: Medium
  Tags: Array, Two Pointers, Binary Search, Greedy, Sorting
  Time:
  Space:
*/

class Solution {
public:
  static int triangleNumber(std::vector<int> nums) {
    std::sort(nums.begin(), nums.end());

    int cnt = 0;
    for (int k = nums.size() - 1; k >= 0; --k) {
      int i = 0, j = k - 1;
      while (i < j) {
        if (nums[i] + nums[j] > nums[k]) {
          cnt += j - i;
          --j;
        } else {
          ++i;
        }
      }
    }
    return cnt;
  }
};
