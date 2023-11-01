#pragma once

#include <algorithm>
#include <vector>

/*
  2553. Separate the Digits in an Array
  https://leetcode.com/problems/separate-the-digits-in-an-array/
  Difficulty: Easy
  Tags: Array, Simulation
  Time:
  Space:
*/

class Solution {
public:
  static std::vector<int> separateDigits(const std::vector<int> &nums) {
    std::vector<int> ans;
    for (int i = nums.size() - 1; i >= 0; --i) {
      for (auto num = nums[i]; num; num /= 10) {
        ans.push_back(num % 10);
      }
    }
    std::reverse(ans.begin(), ans.end());
    return ans;
  }
};
