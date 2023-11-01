#pragma once

#include <ranges>
#include <unordered_map>
#include <vector>

/*
  1640. Check Array Formation Through Concatenation
  https://leetcode.com/problems/check-array-formation-through-concatenation/
  Difficulty: Easy
  Tags: Array, Hash Table
  Time:
  Space:
*/

class Solution {
public:
  static bool canFormArray(const std::vector<int> &arr,
                           const std::vector<std::vector<int>> &pieces) {
    std::unordered_map<int, int> map;
    for (int i = 0; i < std::ssize(pieces); ++i) {
      map[pieces[i][0]] = i;
    }

    std::vector<int> concatenation;
    for (auto a : arr) {
      if (map.contains(a)) {
        std::ranges::copy(pieces[map[a]], std::back_inserter(concatenation));
      }
    }
    return concatenation == arr;
  }
};
