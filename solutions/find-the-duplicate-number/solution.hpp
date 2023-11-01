#pragma once

#include <vector>

/*
  287. Find the Duplicate Number
  https://leetcode.com/problems/find-the-duplicate-number/
  Difficulty: Medium
  Tags: Array, Two Pointers, Binary Search, Bit Manipulation
  Time:
  Space:
*/

class Solution {
public:
  static int findDuplicate(const std::vector<int> &nums) {
    int slow = 0, fast = 0;
    do {
      slow = nums[slow];
      fast = nums[nums[fast]];
    } while (slow != fast);

    slow = 0;
    while (slow != fast) {
      slow = nums[slow];
      fast = nums[fast];
    }
    return slow;
  }
};
