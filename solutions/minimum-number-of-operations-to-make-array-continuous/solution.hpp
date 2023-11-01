#pragma once

#include <algorithm>
#include <vector>

/*
  2009. Minimum Number of Operations to Make Array Continuous
  https://leetcode.com/problems/minimum-number-of-operations-to-make-array-continuous/
  Difficulty: Hard
  Tags: Array, Binary Search
  Time:
  Space:
*/

class Solution {
public:
  static int minOperations(std::vector<int> nums) {
    const auto n = nums.size();

    std::sort(nums.begin(), nums.end());
    nums.erase(std::unique(nums.begin(), nums.end()), nums.end());

    auto ans = n - 1;
    for (auto it = nums.begin(); it != nums.end(); ++it) {
      auto ub = std::upper_bound(it, nums.end(), *it + n - 1);
      ans = std::min(ans, n - std::distance(it, ub));
    }
    return ans;
  }
};
