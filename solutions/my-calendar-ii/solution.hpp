#pragma once

#include <algorithm>
#include <vector>

// Time:
// Space:

class MyCalendarTwo {
private:
  std::vector<std::pair<int, int>> intervals;
  std::vector<std::pair<int, int>> overlaps;

public:
  bool book(int start, int end) {
    for (const auto &[s, e] : overlaps) {
      if (e > start && end > s) {
        return false;
      }
    }

    for (const auto &[s, e] : intervals) {
      if (e > start && end > s) {
        overlaps.push_back({std::max(s, start), std::min(e, end)});
      }
    }

    intervals.push_back({start, end});
    return true;
  }
};
