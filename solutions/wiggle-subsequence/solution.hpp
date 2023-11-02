#pragma once

#include <algorithm>
#include <vector>

// Time:
// Space:

class Solution {
public:
  static int wiggleMaxLength(const std::vector<int> &nums) {
    int positive = 1, negative = 1;

    for (size_t i = 1; i < nums.size(); i++) {
      if (nums[i - 1] < nums[i]) {
        negative = positive + 1;
      }
      if (nums[i - 1] > nums[i]) {
        positive = negative + 1;
      }
    }
    return std::max(positive, negative);
  }
};
