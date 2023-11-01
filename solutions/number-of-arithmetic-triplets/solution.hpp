#pragma once

#include <unordered_set>
#include <vector>

/*
  2367. Number of Arithmetic Triplets
  https://leetcode.com/problems/number-of-arithmetic-triplets/
  Difficulty: Easy
  Tags: Array, Hash Table, Two Pointers, Enumeration
  Time:
  Space:
*/

class Solution {
public:
  static int arithmeticTriplets(const std::vector<int> &nums, int diff) {
    std::unordered_set<int> set(nums.begin(), nums.end());

    int cnt = 0;
    for (auto a : nums) {
      if (set.contains(a + diff) && set.contains(a + 2 * diff)) {
        ++cnt;
      }
    }
    return cnt;
  }
};
