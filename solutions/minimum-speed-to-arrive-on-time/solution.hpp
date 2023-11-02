#pragma once

#include <vector>

// Time:
// Space:

class Solution {
public:
  static int minSpeedOnTime(const std::vector<int> &dist, double hour) {
    if (dist.size() - 1 >= hour) {
      return -1;
    }

    int left = 1, right = 1e7;
    while (left < right) {
      const auto speed = left + (right - left) / 2;

      double time = 0;
      for (size_t i = 0; i < dist.size() - 1; ++i) {
        time += (dist[i] + speed - 1) / speed;
      }
      time += dist.back() * 1.0 / speed;

      time > hour ? left = speed + 1 : right = speed;
    }
    return left;
  }
};
