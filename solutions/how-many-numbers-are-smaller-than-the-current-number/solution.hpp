#pragma once

#include <numeric>
#include <vector>

/*
  1365. How Many Numbers Are Smaller Than the Current Number
  https://leetcode.com/problems/how-many-numbers-are-smaller-than-the-current-number/
  Difficulty: Easy
  Tags: Array, Hash Table, Sorting, Counting
  Time:
  Space:
*/

class Solution {
public:
  static constexpr int kMaxValue = 100;

  static std::vector<int>
  smallerNumbersThanCurrent(const std::vector<int> &nums) {
    std::vector<int> counter(kMaxValue + 1);
    for (auto a : nums) {
      ++counter[a];
    }

    std::partial_sum(counter.begin(), counter.end(), counter.begin());

    std::vector<int> ans(nums.size());
    for (size_t i = 0; i < nums.size(); ++i) {
      ans[i] = nums[i] ? counter[nums[i] - 1] : 0;
    }
    return ans;
  }
};
