#pragma once

#include <vector>

class Solution {
public:
  static int missingNumber(const std::vector<int> &nums) {
    int n = nums.size();
    return n * (n + 1) / 2 - std::accumulate(nums.begin(), nums.end(), 0);
  }
};
