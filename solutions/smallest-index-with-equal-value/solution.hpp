#pragma once

#include <vector>

// Time:
// Space:

class Solution {
public:
  static int smallestEqual(const std::vector<int> &nums) {
    for (int i = 0; i < std::ssize(nums); ++i) {
      if (i % 10 == nums[i]) {
        return i;
      }
    }
    return -1;
  }
};
