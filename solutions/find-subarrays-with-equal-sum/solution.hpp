#pragma once

#include <unordered_set>
#include <vector>

/*
  2395. Find Subarrays With Equal Sum
  https://leetcode.com/problems/find-subarrays-with-equal-sum/
  Difficulty: Easy
  Tags: Array, Hash Table
  Time:
  Space:
*/

class Solution {
public:
  static bool findSubarrays(const std::vector<int> &nums) {
    std::unordered_set<int> set;
    for (size_t i = 1; i < nums.size(); ++i) {
      if (auto [_, inserted] = set.insert(nums[i - 1] + nums[i]); !inserted) {
        return true;
      }
    }
    return false;
  }
};
