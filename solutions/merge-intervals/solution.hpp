#pragma once

#include <algorithm>
#include <vector>

// Time:
// Space:

class Solution {
public:
  static std::vector<std::vector<int>>
  merge(std::vector<std::vector<int>> intervals) {
    std::sort(intervals.begin(), intervals.end());

    std::vector<std::vector<int>> merged;
    auto interval = intervals.front();
    for (size_t i = 0; i < intervals.size(); ++i) {
      if (interval[1] >= intervals[i][0]) {
        interval[1] = std::max(interval[1], intervals[i][1]);
      } else {
        merged.push_back(interval);
        interval = intervals[i];
      }
    }
    merged.push_back(interval);
    return merged;
  }
};
