#pragma once

#include <unordered_set>
#include <vector>

/*
  2357. Make Array Zero by Subtracting Equal Amounts
  https://leetcode.com/problems/make-array-zero-by-subtracting-equal-amounts/
  Difficulty: Easy
  Tags: Array, Hash Table, Greedy, Sorting, Heap (Priority Queue), Simulation
  Time:
  Space:
*/

class Solution {
public:
  static int minimumOperations(const std::vector<int> &nums) {
    std::unordered_set<int> set(nums.begin(), nums.end());
    set.erase(0);
    return set.size();
  }
};
