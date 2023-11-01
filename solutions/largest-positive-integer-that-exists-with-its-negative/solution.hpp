#pragma once

#include <unordered_set>
#include <vector>

/*
  2441. Largest Positive Integer That Exists With Its Negative
  https://leetcode.com/problems/largest-positive-integer-that-exists-with-its-negative/
  Difficulty: Easy
  Tags: Array, Hash Table, Two Pointers, Sorting
  Time:
  Space:
*/

class Solution {
public:
  static int findMaxK(const std::vector<int> &nums) {
    std::unordered_set<int> set;
    int max = -1;
    for (auto num : nums) {
      if (set.contains(-num)) {
        max = std::max(max, std::abs(num));
      }
      set.insert(num);
    }
    return max;
  }
};
