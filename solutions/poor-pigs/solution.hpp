#pragma once

#include <cmath>

/*
  458. Poor Pigs
  https://leetcode.com/problems/poor-pigs/
  Difficulty: Hard
  Tags: Math, Dynamic Programming, Combinatorics
  Time:
  Space:
*/

class Solution {
public:
  static int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
    const auto attempts = minutesToTest / minutesToDie;
    return std::ceil(std::log2(buckets) / std::log2(attempts + 1));
  }
};
