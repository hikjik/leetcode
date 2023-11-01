#pragma once

/*
  2651. Calculate Delayed Arrival Time
  https://leetcode.com/problems/calculate-delayed-arrival-time/
  Difficulty: Easy
  Tags: Math
  Time:
  Space:
*/

class Solution {
public:
  static int findDelayedArrivalTime(int arrivalTime, int delayedTime) {
    return (arrivalTime + delayedTime) % 24;
  }
};
