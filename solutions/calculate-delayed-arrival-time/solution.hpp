#pragma once

// Time:
// Space:

class Solution {
public:
  static int findDelayedArrivalTime(int arrivalTime, int delayedTime) {
    return (arrivalTime + delayedTime) % 24;
  }
};
