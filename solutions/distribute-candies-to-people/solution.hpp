#pragma once

#include <vector>

/*
  1103. Distribute Candies to People
  https://leetcode.com/problems/distribute-candies-to-people/
  Difficulty: Easy
  Tags: Math, Simulation
  Time:
  Space:
*/

class Solution {
public:
  static std::vector<int> distributeCandies(int candies, int num_people) {
    std::vector<int> ans(num_people);
    for (int i = 0; candies > 0; ++i, candies -= i) {
      ans[i % num_people] += std::min(i + 1, candies);
    }
    return ans;
  }
};
