#pragma once

#include <vector>

// Time:
// Space:

class Solution {
public:
  static int distanceBetweenBusStops(const std::vector<int> &distance,
                                     int start, int destination) {
    if (start > destination) {
      std::swap(start, destination);
    }

    int clockwise = 0, counterclockwise = 0;
    for (int i = 0; i < std::ssize(distance); ++i) {
      if (i >= start && i < destination) {
        clockwise += distance[i];
      } else {
        counterclockwise += distance[i];
      }
    }
    return std::min(clockwise, counterclockwise);
  }
};
