#pragma once

/*
  2739. Total Distance Traveled
  https://leetcode.com/problems/total-distance-traveled/
  Difficulty: Easy
  Tags: Math, Simulation
  Time:
  Space:
*/

class Solution {
public:
  static int distanceTraveled(int mainTank, int additionalTank) {
    return (mainTank + std::min((mainTank - 1) / 4, additionalTank)) * 10;
  }
};
