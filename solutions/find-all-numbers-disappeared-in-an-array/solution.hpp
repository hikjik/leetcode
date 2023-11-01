#pragma once

#include <cmath>
#include <vector>

/*
  448. Find All Numbers Disappeared in an Array
  https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/
  Difficulty: Easy
  Tags: Array, Hash Table
  Time:
  Space:
*/

class Solution {
public:
  static std::vector<int> findDisappearedNumbers(std::vector<int> nums) {
    const int n = nums.size();

    for (auto a : nums) {
      const auto index = std::abs(a) - 1;
      nums[index] = -std::abs(nums[index]);
    }

    std::vector<int> ans;
    for (int i = 0; i < n; ++i) {
      if (nums[i] > 0) {
        ans.push_back(i + 1);
      }
    }
    return ans;
  }
};
