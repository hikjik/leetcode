#pragma once

#include <algorithm>
#include <vector>

/*
  55. Jump Game
  https://leetcode.com/problems/jump-game/
  Difficulty: Medium
  Tags: Array, Dynamic Programming, Greedy
  Time:
  Space:
*/

class Solution {
public:
  static bool canJump(std::vector<int> nums) {
    for (size_t j = 1; j < nums.size(); ++j) {
      if (nums[j - 1] > 0) {
        nums[j] = std::max(nums[j - 1] - 1, nums[j]);
      } else {
        return false;
      }
    }
    return true;
  }
};
