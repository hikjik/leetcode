#pragma once

#include <algorithm>
#include <vector>

/*
  989. Add to Array-Form of Integer
  https://leetcode.com/problems/add-to-array-form-of-integer/
  Difficulty: Easy
  Tags: Array, Math
  Time:
  Space:
*/

class Solution {
public:
  static std::vector<int> addToArrayForm(const std::vector<int> &nums, int k) {
    std::vector<int> sum;

    for (int i = nums.size() - 1; i >= 0 || k; --i) {
      const auto num = k + (i >= 0 ? nums[i] : 0);
      sum.push_back(num % 10);
      k = num / 10;
    }

    std::reverse(sum.begin(), sum.end());
    return sum;
  }
};
