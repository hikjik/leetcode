#pragma once

#include <vector>

/*
  1018. Binary Prefix Divisible By 5
  https://leetcode.com/problems/binary-prefix-divisible-by-5/
  Difficulty: Easy
  Tags: Array
  Time:
  Space:
*/

class Solution {
public:
  static std::vector<bool> prefixesDivBy5(const std::vector<int> &nums) {
    std::vector<bool> ans(nums.size());
    for (int i = 0, num = 0; i < std::ssize(nums); ++i) {
      num = (num * 2 + nums[i]) % 5;
      ans[i] = num == 0;
    }
    return ans;
  }
};
