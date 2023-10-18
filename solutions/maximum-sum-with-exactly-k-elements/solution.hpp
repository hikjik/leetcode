#pragma once

#include <algorithm>
#include <vector>

class Solution {
public:
  static int maximizeSum(const std::vector<int> &nums, int k) {
    return *std::max_element(nums.begin(), nums.end()) * k + (k - 1) * k / 2;
  }
};
