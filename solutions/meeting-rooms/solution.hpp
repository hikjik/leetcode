#pragma once

#include <vector>

// Time: O(NlogN)
// Space: O(N)

class Solution {
public:
  static bool canAttendMeetings(std::vector<std::vector<int>> intervals) {
    std::ranges::sort(intervals);
    for (int i = 0; i + 1 < std::ssize(intervals); ++i) {
      if (intervals[i][1] > intervals[i + 1][0]) {
        return false;
      }
    }
    return true;
  }
};
