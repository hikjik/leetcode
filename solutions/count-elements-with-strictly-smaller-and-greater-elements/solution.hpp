#pragma once

#include <algorithm>
#include <vector>

/*
  2148. Count Elements With Strictly Smaller and Greater Elements
  https://leetcode.com/problems/count-elements-with-strictly-smaller-and-greater-elements/
  Difficulty: Easy
  Tags: Array, Sorting
  Time:
  Space:
*/

class Solution {
public:
  static int countElements(const std::vector<int> &nums) {
    const auto [it_min, it_max] = std::minmax_element(nums.begin(), nums.end());
    const auto min = *it_min, max = *it_max;
    return std::count_if(nums.begin(), nums.end(),
                         [min, max](int a) { return min < a && a < max; });
  }
};
