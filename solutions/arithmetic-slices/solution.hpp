#pragma once

#include <vector>

class Solution {
public:
  static int numberOfArithmeticSlices(const std::vector<int> &nums) {
    if (nums.size() < 3) {
      return 0;
    }

    int arithmetic_slices_count = 0;
    int count = 0;
    int difference = nums[1] - nums[0];
    for (size_t i = 1; i < nums.size() - 1; ++i) {
      if (nums[i + 1] - nums[i] == difference) {
        count++;
      } else {
        difference = nums[i + 1] - nums[i];
        count = 0;
      }
      arithmetic_slices_count += count;
    }

    return arithmetic_slices_count;
  }
};
