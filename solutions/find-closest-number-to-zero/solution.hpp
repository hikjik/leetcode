#pragma once

#include <algorithm>
#include <cmath>
#include <vector>

// Time:
// Space:

class Solution {
public:
  static int findClosestNumber(const std::vector<int> &nums) {
    return *std::min_element(nums.begin(), nums.end(), [](int a, int b) {
      return std::make_tuple(std::abs(a), b) < std::make_tuple(std::abs(b), a);
    });
  }
};
