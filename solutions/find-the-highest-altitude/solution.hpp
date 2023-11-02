#pragma once

#include <algorithm>

// Time:
// Space:

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
