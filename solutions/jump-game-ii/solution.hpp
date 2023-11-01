#pragma once

#include <algorithm>
#include <vector>

/*
  45. Jump Game II
  https://leetcode.com/problems/jump-game-ii/
  Difficulty: Medium
  Tags: Array, Dynamic Programming, Greedy
  Time:
  Space:
*/

class Solution {
public:
  static int jump(std::vector<int> nums) {
    int jumps = 0;
    size_t max_reach = 0, cur_reach = 0;
    for (size_t i = 0; i < nums.size() - 1; ++i) {
      max_reach = std::max(max_reach, i + nums[i]);
      if (cur_reach == i) {
        ++jumps;
        cur_reach = max_reach;
      }
    }
    return jumps;
  }
};
