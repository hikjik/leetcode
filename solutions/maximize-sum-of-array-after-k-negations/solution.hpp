#pragma once

#include <algorithm>
#include <numeric>
#include <vector>

/*
  1005. Maximize Sum Of Array After K Negations
  https://leetcode.com/problems/maximize-sum-of-array-after-k-negations/
  Difficulty: Easy
  Tags: Array, Greedy, Sorting
  Time:
  Space:
*/

class Solution {
public:
  static int largestSumAfterKNegations(std::vector<int> nums, int k) {
    std::make_heap(nums.begin(), nums.end(), std::greater<>());
    while (k--) {
      std::pop_heap(nums.begin(), nums.end(), std::greater<>());
      nums.back() *= -1;
      std::push_heap(nums.begin(), nums.end(), std::greater<>());
    }
    return std::accumulate(nums.begin(), nums.end(), 0);
  }
};
