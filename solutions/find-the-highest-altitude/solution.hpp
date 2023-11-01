#pragma once

#include <algorithm>

/*
  1732. Find the Highest Altitude
  https://leetcode.com/problems/find-the-highest-altitude/
  Difficulty: Easy
  Tags: Array, Prefix Sum
  Time:
  Space:
*/

class Solution {
public:
  static int largestAltitude(const std::vector<int> &gain) {
    int max_altitude = 0, altitude = 0;
    for (auto g : gain) {
      altitude += g;
      max_altitude = std::max(max_altitude, altitude);
    }
    return max_altitude;
  }
};
