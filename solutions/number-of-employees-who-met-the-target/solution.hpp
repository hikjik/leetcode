#pragma once

#include <algorithm>
#include <vector>

// Time:
// Space:

class Solution {
public:
  static int numberOfEmployeesWhoMetTarget(const std::vector<int> &hours,
                                           int target) {
    return std::count_if(hours.begin(), hours.end(),
                         [target](int h) { return h >= target; });
  }
};
