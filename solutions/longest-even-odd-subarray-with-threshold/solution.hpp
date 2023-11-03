#pragma once

#include <vector>

// Time:
// Space:

class Solution {
public:
  static int longestAlternatingSubarray(const std::vector<int> &nums,
                                        int threshold) {
    int max_length = 0, length = 0;
    for (size_t i = 0; i < nums.size(); ++i) {
      if (nums[i] > threshold) {
        length = 0;
      } else if (length && nums[i] % 2 != nums[i - 1] % 2) {
        ++length;
      } else {
        length = nums[i] % 2 == 0;
      }
      max_length = std::max(max_length, length);
    }
    return max_length;
  }
};
