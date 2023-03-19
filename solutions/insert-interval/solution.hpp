#pragma once

#include <algorithm>
#include <vector>

class Solution {
public:
  static std::vector<std::vector<int>>
  insert(const std::vector<std::vector<int>> &intervals,
         std::vector<int> new_interval) {
    size_t i = 0, n = intervals.size();
    std::vector<std::vector<int>> updated_intervals;

    while (i < n && intervals[i][1] < new_interval[0]) {
      updated_intervals.push_back(intervals[i++]);
    }

    while (i < n && intervals[i][0] <= new_interval[1]) {
      new_interval[0] = std::min(new_interval[0], intervals[i][0]);
      new_interval[1] = std::max(new_interval[1], intervals[i][1]);
      ++i;
    }
    updated_intervals.push_back(new_interval);

    while (i < n) {
      updated_intervals.push_back(intervals[i++]);
    }

    return updated_intervals;
  }
};
