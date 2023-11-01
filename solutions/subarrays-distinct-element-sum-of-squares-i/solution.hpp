#pragma once

#include <unordered_set>
#include <vector>

/*
  2913. Subarrays Distinct Element Sum of Squares I
  https://leetcode.com/problems/subarrays-distinct-element-sum-of-squares-i/
  Difficulty: Easy
  Tags: Array, Hash Table
  Time:
  Space:
*/

class Solution {
public:
  static int sumCounts(const std::vector<int> &nums) {
    int ans = 0;
    for (size_t i = 0; i < nums.size(); ++i) {
      std::unordered_set<int> set;
      for (size_t j = i; j < nums.size(); ++j) {
        set.insert(nums[j]);
        ans += set.size() * set.size();
      }
    }
    return ans;
  }
};
