#pragma once

#include <algorithm>
#include <vector>

// Time: O(N)
// Space: O(1)

class Solution {
public:
  static std::vector<std::vector<int>>
  insert(const std::vector<std::vector<int>> &intervals,
         std::vector<int> new_interval) {
    const int n = intervals.size();

    std::vector<std::vector<int>> ans;

    int i = 0;
    for (; i < n && intervals[i][1] < new_interval[0]; ++i) {
      ans.push_back(intervals[i]);
    }

    for (; i < n && intervals[i][0] <= new_interval[1]; ++i) {
      new_interval[0] = std::min(new_interval[0], intervals[i][0]);
      new_interval[1] = std::max(new_interval[1], intervals[i][1]);
    }
    ans.push_back(new_interval);

    for (; i < n; ++i) {
      ans.push_back(intervals[i]);
    }

    return ans;
  }
};
