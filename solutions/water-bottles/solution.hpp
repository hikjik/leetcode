#pragma once

// Time:
// Space:

class Solution {
public:
  static int numWaterBottles(int numBottles, int numExchange) {
    return numBottles + (numBottles - 1) / (numExchange - 1);
  }
};
