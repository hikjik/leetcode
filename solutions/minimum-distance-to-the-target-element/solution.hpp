#pragma once

#include <cmath>
#include <vector>

// Time:
// Space:

class Solution {
public:
  static int getMinDistance(const std::vector<int> &nums, int target,
                            int start) {
    const int n = nums.size();
    auto distance = n - 1;
    for (int i = 0; i < n; ++i) {
      if (nums[i] == target) {
        distance = std::min(distance, std::abs(start - i));
      }
    }
    return distance;
  }
};
