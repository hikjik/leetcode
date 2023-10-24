#pragma once

#include <string>
#include <vector>

class Solution {
public:
  static char slowestKey(const std::vector<int> &releaseTimes,
                         std::string keysPressed) {
    auto max_duration = releaseTimes[0];
    auto slowest_key = keysPressed[0];
    for (size_t i = 1; i < releaseTimes.size(); ++i) {
      const auto duration = releaseTimes[i] - releaseTimes[i - 1];
      if (duration > max_duration) {
        max_duration = duration;
        slowest_key = keysPressed[i];
      } else if (duration == max_duration) {
        slowest_key = std::max(slowest_key, keysPressed[i]);
      }
    }
    return slowest_key;
  }
};
