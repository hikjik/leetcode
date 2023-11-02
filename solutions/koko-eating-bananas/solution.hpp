#pragma once

#include <vector>

// Time:
// Space:

class Solution {
public:
  static const int MAX_EAT_SPEED = 1e9;

  static int minEatingSpeed(const std::vector<int> &piles, int h) {
    int left = 1, right = MAX_EAT_SPEED;
    while (left < right) {
      const auto middle = left + (right - left) / 2;

      int hours = 0;
      for (auto pile : piles) {
        hours += (pile + middle - 1) / middle;
      }

      if (hours > h) {
        left = middle + 1;
      } else {
        right = middle;
      }
    }
    return left;
  }
};
