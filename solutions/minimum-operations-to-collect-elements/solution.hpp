#pragma once

#include <unordered_set>
#include <vector>

/*
  2869. Minimum Operations to Collect Elements
  https://leetcode.com/problems/minimum-operations-to-collect-elements/
  Difficulty: Easy
  Tags: Array, Hash Table
  Time:
  Space:
*/

class Solution {
public:
  static int minOperations(const std::vector<int> &nums, int k) {
    std::unordered_set<int> set;
    for (int i = nums.size() - 1; i >= 0; --i) {
      if (nums[i] <= k) {
        set.insert(nums[i]);
        if (set.size() == k * 1ULL) {
          return nums.size() - i;
        }
      }
    }
    throw;
  }
};
