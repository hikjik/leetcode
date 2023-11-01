#pragma once

#include <vector>

/*
  303. Range Sum Query - Immutable
  https://leetcode.com/problems/range-sum-query-immutable/
  Difficulty: Easy
  Tags: Array, Design, Prefix Sum
  Time:
  Space:
*/

class NumArray {
public:
  NumArray(std::vector<int> nums) : prefix_sums_(nums.size() + 1, 0) {
    for (size_t i = 1; i < prefix_sums_.size(); ++i) {
      prefix_sums_[i] = prefix_sums_[i - 1] + nums[i - 1];
    }
  }

  int sumRange(int left, int right) {
    return prefix_sums_[right + 1] - prefix_sums_[left];
  }

private:
  std::vector<int> prefix_sums_;
};
