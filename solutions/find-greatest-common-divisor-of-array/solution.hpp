#pragma once

#include <numeric>
#include <vector>

/*
  1979. Find Greatest Common Divisor of Array
  https://leetcode.com/problems/find-greatest-common-divisor-of-array/
  Difficulty: Easy
  Tags: Array, Math, Number Theory
  Time:
  Space:
*/

class Solution {
public:
  static int findGCD(const std::vector<int> &nums) {
    const auto [it_min, it_max] = std::minmax_element(nums.begin(), nums.end());
    return std::gcd(*it_min, *it_max);
  }
};
