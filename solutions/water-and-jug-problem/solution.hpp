#pragma once

#include <numeric>

/*
  365. Water and Jug Problem
  https://leetcode.com/problems/water-and-jug-problem/
  Difficulty: Medium
  Tags: Math, Depth-First Search, Breadth-First Search
  Time:
  Space:
*/

class Solution {
public:
  static bool canMeasureWater(int jug1Capacity, int jug2Capacity,
                              int targetCapacity) {

    return targetCapacity == 0 ||
           jug1Capacity + jug2Capacity >= targetCapacity &&
               targetCapacity % std::gcd(jug1Capacity, jug2Capacity) == 0;
  }
};
