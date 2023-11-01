#pragma once

#include <unordered_set>
#include <vector>

/*
  1346. Check If N and Its Double Exist
  https://leetcode.com/problems/check-if-n-and-its-double-exist/
  Difficulty: Easy
  Tags: Array, Hash Table, Two Pointers, Binary Search, Sorting
  Time:
  Space:
*/

class Solution {
public:
  static bool checkIfExist(const std::vector<int> &arr) {
    std::unordered_set<int> seen;
    for (auto a : arr) {
      if (seen.count(2 * a) || a % 2 == 0 && seen.count(a / 2)) {
        return true;
      }
      seen.insert(a);
    }
    return false;
  }
};
