#pragma once

#include <algorithm>

// Time: O(1)
// Space: O(1)

class Solution {
private:
public:
  static int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1,
                         int bx2, int by2) {
    const auto [cx1, cx2, cy1, cy2] =
        intersection(ax1, ay1, ax2, ay2, bx1, by1, bx2, by2);
    return area(ax1, ax2, ay1, ay2) + area(bx1, bx2, by1, by2) -
           area(cx1, cx2, cy1, cy2);
  }

private:
  static std::tuple<int, int, int, int> intersection(int ax1, int ay1, int ax2,
                                                     int ay2, int bx1, int by1,
                                                     int bx2, int by2) {
    if (ax2 < bx1 || bx2 < ax1 || ay2 < by1 || by2 < ay1) {
      return {0, 0, 0, 0};
    }
    return {std::max(ax1, bx1), std::min(ax2, bx2), std::max(ay1, by1),
            std::min(ay2, by2)};
  }

  static int area(int x1, int x2, int y1, int y2) {
    return (x2 - x1) * (y2 - y1);
  }
};
