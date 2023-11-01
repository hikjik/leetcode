#pragma once

#include <vector>

/*
  1822. Sign of the Product of an Array
  https://leetcode.com/problems/sign-of-the-product-of-an-array/
  Difficulty: Easy
  Tags: Array, Math
  Time:
  Space:
*/

class Solution {
public:
  static int arraySign(std::vector<int> nums) {
    int sign = 1;
    for (auto num : nums) {
      if (!num) {
        sign = 0;
      }
      if (num < 0) {
        sign *= -1;
      }
    }
    return sign;
  }
};
