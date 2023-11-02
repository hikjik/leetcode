#pragma once

#include <vector>

// Time:
// Space:

class Solution {
public:
  static bool isRectangleOverlap(const std::vector<int> &rec1,
                                 const std::vector<int> &rec2) {
    return isSegmentOverlap({rec1[0], rec1[2]}, {rec2[0], rec2[2]}) &&
           isSegmentOverlap({rec1[1], rec1[3]}, {rec2[1], rec2[3]});
  }

  static bool isSegmentOverlap(const std::pair<int, int> &segment1,
                               const std::pair<int, int> &segment2) {
    return segment1.first < segment2.second && segment2.first < segment1.second;
  }
};
