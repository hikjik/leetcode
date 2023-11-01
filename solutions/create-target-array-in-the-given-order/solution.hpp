#pragma once

#include <vector>

/*
  1389. Create Target Array in the Given Order
  https://leetcode.com/problems/create-target-array-in-the-given-order/
  Difficulty: Easy
  Tags: Array, Simulation
  Time:
  Space:
*/

class Solution {
public:
  static std::vector<int> createTargetArray(const std::vector<int> &nums,
                                            const std::vector<int> &index) {
    std::vector<int> ans;
    for (size_t i = 0; i < nums.size(); ++i) {
      ans.insert(ans.begin() + index[i], nums[i]);
    }
    return ans;
  }
};
