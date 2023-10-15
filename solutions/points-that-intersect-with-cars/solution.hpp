#pragma once

#include <algorithm>
#include <vector>

class Solution {
public:
  static int numberOfPoints(std::vector<std::vector<int>> nums) {
    std::sort(nums.begin(), nums.end());
    int count = 0, end = 0;
    for (const auto &pair : nums) {
      if (pair[1] > end) {
        count += pair[1] - std::max(pair[0] - 1, end);
        end = pair[1];
      }
    }
    return count;
  }
};
