#pragma once

#include <vector>

class Solution {
public:
  static int findPoisonedDuration(const std::vector<int> &timeSeries,
                                  int duration) {
    int ans = 0;
    for (int i = 0; i + 1 < std::ssize(timeSeries); ++i) {
      ans += std::min(timeSeries[i + 1] - timeSeries[i], duration);
    }
    return ans + duration;
  }
};
