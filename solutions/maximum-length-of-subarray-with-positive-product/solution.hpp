#pragma once

#include <limits>
#include <vector>

// Time:
// Space:

class Solution {
public:
  static int getMaxLen(const std::vector<int> &nums) {
    int max_length = std::numeric_limits<int>::min();

    int max_positive = 0, max_negative = 0;
    for (auto num : nums) {
      if (num == 0) {
        max_positive = max_negative = 0;
      } else {
        max_positive += 1;
        max_negative = max_negative > 0 ? max_negative + 1 : 0;
        if (num < 0) {
          std::swap(max_negative, max_positive);
        }
      }
      max_length = std::max(max_length, max_positive);
    }
    return max_length;
  }
};
