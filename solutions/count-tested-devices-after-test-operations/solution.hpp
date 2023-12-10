#pragma once

#include <vector>

// Time: O(N)
// Space: O(1)

class Solution {
public:
  static int countTestedDevices(const std::vector<int> &batteryPercentages) {
    int ans = 0;
    for (auto a : batteryPercentages) {
      if (a > ans) {
        ++ans;
      }
    }
    return ans;
  }
};
