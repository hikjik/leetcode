#pragma once

#include <unordered_map>
#include <unordered_set>
#include <vector>

/*
  1207. Unique Number of Occurrences
  https://leetcode.com/problems/unique-number-of-occurrences/
  Difficulty: Easy
  Tags: Array, Hash Table
  Time:
  Space:
*/

class Solution {
public:
  static bool uniqueOccurrences(const std::vector<int> &arr) {
    std::unordered_map<int, int> map;
    for (auto a : arr) {
      ++map[a];
    }
    std::unordered_set<int> set;
    for (const auto &[a, f] : map) {
      if (set.count(f)) {
        return false;
      }
      set.insert(f);
    }
    return true;
  }
};
