#pragma once

#include <algorithm>
#include <vector>

/*
  198. House Robber
  https://leetcode.com/problems/house-robber/
  Difficulty: Medium
  Tags: Array, Dynamic Programming
  Time:
  Space:
*/

class Solution {
public:
  static int rob(const std::vector<int> &nums) {
    int a = 0, b = 0, c = 0;
    for (auto num : nums) {
      const auto d = std::max(num + a, num + b);
      a = b, b = c, c = d;
    }
    return std::max(b, c);
  }
};
