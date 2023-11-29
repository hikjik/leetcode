#pragma once

#include <ranges>
#include <vector>

// Time: O(NlogN)
// Space: O(N)

class Solution {
public:
  static int maxWidthOfVerticalArea(std::vector<std::vector<int>> points) {
    std::ranges::sort(points);
    int ans = 0;
    for (int i = 1; i < std::ssize(points); ++i) {
      ans = std::max(ans, points[i][0] - points[i - 1][0]);
    }
    return ans;
  }
};
