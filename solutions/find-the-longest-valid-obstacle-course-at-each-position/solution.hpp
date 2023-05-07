#pragma once

#include <algorithm>
#include <vector>

class Solution {
public:
  static std::vector<int>
  longestObstacleCourseAtEachPosition(const std::vector<int> &obstacles) {
    std::vector<int> dp, ans;
    for (auto obstacle : obstacles) {
      auto it = std::upper_bound(dp.begin(), dp.end(), obstacle);
      ans.push_back(std::distance(dp.begin(), it) + 1);
      if (it == dp.end()) {
        dp.push_back(obstacle);
      } else {
        *it = obstacle;
      }
    }
    return ans;
  }
};
