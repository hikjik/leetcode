#pragma once

#include <algorithm>
#include <vector>

// Time: O(N)
// Space: O(1)

class Solution {
public:
  static int maxArea(const std::vector<int> &height) {
    int max_area = 0;
    for (int l = 0, r = height.size() - 1; l < r;) {
      const auto area = std::min(height[l], height[r]) * (r - l);
      max_area = std::max(max_area, area);
      height[l] < height[r] ? ++l : --r;
    }
    return max_area;
  }
};
