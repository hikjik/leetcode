#pragma once

#include <algorithm>
#include <unordered_map>
#include <vector>

/*
  1636. Sort Array by Increasing Frequency
  https://leetcode.com/problems/sort-array-by-increasing-frequency/
  Difficulty: Easy
  Tags: Array, Hash Table, Sorting
  Time:
  Space:
*/

class Solution {
public:
  static std::vector<int> frequencySort(std::vector<int> nums) {
    std::unordered_map<int, int> counter;
    for (auto a : nums) {
      ++counter[a];
    }
    std::sort(nums.begin(), nums.end(), [&](int a, int b) {
      return std::make_pair(counter[a], b) < std::make_pair(counter[b], a);
    });
    return nums;
  }
};
