#pragma once

/*
  1518. Water Bottles
  https://leetcode.com/problems/water-bottles/
  Difficulty: Easy
  Tags: Math, Simulation
  Time:
  Space:
*/

class Solution {
public:
  static int numWaterBottles(int numBottles, int numExchange) {
    return numBottles + (numBottles - 1) / (numExchange - 1);
  }
};
