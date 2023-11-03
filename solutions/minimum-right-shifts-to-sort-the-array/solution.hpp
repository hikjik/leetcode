#pragma once

#include <vector>

// Time:
// Space:

class Solution {
public:
  static int minimumRightShifts(const std::vector<int> &nums) {
    const int n = nums.size();
    int count = 0, shifts = 0;
    for (int i = 0; i < n; i++) {
      if (nums[i] >= nums[(i + 1) % n]) {
        ++count;
        shifts = n - i - 1;
      }
    }
    return count == 1 ? shifts : -1;
  }
};
