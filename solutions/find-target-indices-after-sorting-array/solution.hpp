#pragma once

#include <numeric>
#include <ranges>
#include <vector>

/*
  2089. Find Target Indices After Sorting Array
  https://leetcode.com/problems/find-target-indices-after-sorting-array/
  Difficulty: Easy
  Tags: Array, Binary Search, Sorting
  Time:
  Space:
*/

class Solution {
public:
  static std::vector<int> targetIndices(const std::vector<int> &nums,
                                        int target) {
    std::vector<int> ans(std::ranges::count(nums, target));
    std::iota(ans.begin(), ans.end(),
              std::ranges::count_if(nums, [=](int a) { return a < target; }));
    return ans;
  }
};
