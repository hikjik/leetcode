#pragma once

#include <vector>

// Time: O(N)
// Space: O(1)

class Solution {
public:
  static std::vector<std::vector<int>>
  removeInterval(const std::vector<std::vector<int>> &intervals,
                 const std::vector<int> &toBeRemoved) {
    std::vector<std::vector<int>> ans;
    for (const auto &interval : intervals) {
      if (interval[1] <= toBeRemoved[0] || toBeRemoved[1] <= interval[0]) {
        ans.push_back(interval);
      } else {
        if (interval[0] < toBeRemoved[0]) {
          ans.push_back({interval[0], toBeRemoved[0]});
        }
        if (toBeRemoved[1] < interval[1]) {
          ans.push_back({toBeRemoved[1], interval[1]});
        }
      }
    }
    return ans;
  }
};
