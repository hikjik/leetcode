#pragma once

#include <vector>

// Time:
// Space:

class Solution {
public:
  using ll = long long;
  static const ll MAX_TIME = 1e14;

  static ll minimumTime(const std::vector<int> &time, int totalTrips) {
    ll left = 1, right = MAX_TIME;
    while (left < right) {
      const auto middle = left + (right - left) / 2;

      ll trips = 0;
      for (auto t : time) {
        trips += middle / t;
      }

      if (trips < totalTrips) {
        left = middle + 1;
      } else {
        right = middle;
      }
    }
    return left;
  }
};
