#pragma once

#include <vector>

// Time:
// Space:

class Solution {
public:
  static int busyStudent(std::vector<int> startTime, std::vector<int> endTime,
                         int queryTime) {
    int cnt = 0;
    for (int i = 0; i < std::ssize(startTime); ++i) {
      if (startTime[i] <= queryTime && queryTime <= endTime[i]) {
        ++cnt;
      }
    }
    return cnt;
  }
};
