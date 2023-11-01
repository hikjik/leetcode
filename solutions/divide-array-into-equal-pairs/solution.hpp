#pragma once

#include <algorithm>
#include <unordered_map>
#include <vector>

/*
  2206. Divide Array Into Equal Pairs
  https://leetcode.com/problems/divide-array-into-equal-pairs/
  Difficulty: Easy
  Tags: Array, Hash Table, Bit Manipulation, Counting
  Time:
  Space:
*/

class Solution {
public:
  static bool divideArray(const std::vector<int> &nums) {
    std::unordered_map<int, int> counter;
    for (auto a : nums) {
      ++counter[a];
    }
    return std::all_of(counter.begin(), counter.end(),
                       [](const auto &p) { return p.second % 2 == 0; });
  }
};
