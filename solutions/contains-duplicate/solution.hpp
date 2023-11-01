#pragma once

#include <unordered_set>
#include <vector>

/*
  217. Contains Duplicate
  https://leetcode.com/problems/contains-duplicate/
  Difficulty: Easy
  Tags: Array, Hash Table, Sorting
  Time:
  Space:
*/

class Solution {
public:
  static bool containsDuplicate(const std::vector<int> &nums) {
    std::unordered_set<int> set;
    for (auto num : nums) {
      if (set.find(num) != set.end()) {
        return true;
      }
      set.insert(num);
    }
    return false;
  }
};
