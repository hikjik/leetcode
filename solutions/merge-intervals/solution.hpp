#pragma once

#include <algorithm>
#include <vector>

// Time: O(NlogN)
// Space: O(N)

class Solution {
public:
  static std::vector<std::vector<int>>
  merge(std::vector<std::vector<int>> intervals) {
    std::sort(intervals.begin(), intervals.end());
    std::vector<std::vector<int>> ans;
    for (const auto &interval : intervals) {
      if (ans.empty() || ans.back()[1] < interval[0]) {
        ans.push_back(interval);
      } else {
        ans.back()[1] = std::max(ans.back()[1], interval[1]);
      }
    }
    return ans;
  }
};
