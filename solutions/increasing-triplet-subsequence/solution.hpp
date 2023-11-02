#pragma once

#include <climits>
#include <vector>

// Time:
// Space:

class Solution {
public:
  static bool increasingTriplet(const std::vector<int> &nums) {
    int first = INT_MAX, second = INT_MAX;
    for (auto num : nums) {
      if (num <= first) {
        first = num;
      } else if (num <= second) {
        second = num;
      } else {
        return true;
      }
    }
    return false;
  }
};
