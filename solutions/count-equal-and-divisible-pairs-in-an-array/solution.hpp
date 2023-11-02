#pragma once

#include <vector>

// Time:
// Space:

class Solution {
public:
  static int countPairs(const std::vector<int> &nums, int k) {
    int cnt = 0;
    for (size_t i = 0; i < nums.size(); ++i) {
      for (size_t j = i + 1; j < nums.size(); ++j) {
        if (nums[i] == nums[j] && i * j % k == 0) {
          ++cnt;
        }
      }
    }
    return cnt;
  }
};
