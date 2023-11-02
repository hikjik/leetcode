#pragma once

#include <vector>

// Time:
// Space:

class Solution {
public:
  static bool kLengthApart(const std::vector<int> &nums, int k) {
    for (int distance = 0; auto num : nums) {
      if (!num) {
        --distance;
      } else {
        if (distance > 0) {
          return false;
        }
        distance = k;
      }
    }
    return true;
  }
};
