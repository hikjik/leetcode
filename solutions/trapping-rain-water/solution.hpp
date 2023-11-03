#pragma once

#include <vector>

// Time: O(N)
// Space: O(1)

class Solution {
public:
  static int trap(const std::vector<int> &heights) {
    int height = 0, water = 0;
    for (int l = 0, r = heights.size() - 1; l < r;
         heights[l] < heights[r] ? ++l : --r) {
      const auto lower = std::min(heights[l], heights[r]);
      height = std::max(height, lower);
      water += height - lower;
    }
    return water;
  }
};
