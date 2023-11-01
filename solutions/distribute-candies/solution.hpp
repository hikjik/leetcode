#pragma once

#include <unordered_set>
#include <vector>

/*
  575. Distribute Candies
  https://leetcode.com/problems/distribute-candies/
  Difficulty: Easy
  Tags: Array, Hash Table
  Time:
  Space:
*/

class Solution {
public:
  static int distributeCandies(const std::vector<int> &candyType) {
    std::unordered_set<int> types(candyType.begin(), candyType.end());
    return std::min(types.size(), candyType.size() / 2);
  }
};
