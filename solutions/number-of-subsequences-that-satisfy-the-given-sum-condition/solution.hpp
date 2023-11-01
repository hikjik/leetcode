#pragma once

#include <algorithm>
#include <vector>

/*
  1498. Number of Subsequences That Satisfy the Given Sum Condition
  https://leetcode.com/problems/number-of-subsequences-that-satisfy-the-given-sum-condition/
  Difficulty: Medium
  Tags: Array, Two Pointers, Binary Search, Sorting
  Time:
  Space:
*/

class Solution {
private:
  static const int kMod = 1e9 + 7;

public:
  static int numSubseq(std::vector<int> nums, int target) {
    std::sort(nums.begin(), nums.end());

    std::vector<int> powers_of_two(nums.size(), 1);
    for (size_t i = 1; i < nums.size(); ++i) {
      powers_of_two[i] = (powers_of_two[i - 1] * 2) % kMod;
    }

    int cnt = 0;
    int left = 0, right = nums.size() - 1;
    while (left <= right) {
      if (nums[left] + nums[right] <= target) {
        cnt += powers_of_two[right - left];
        cnt %= kMod;
        left++;
      } else {
        right--;
      }
    }
    return cnt;
  }
};
