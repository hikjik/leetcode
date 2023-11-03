#pragma once

#include <vector>

// Time:
// Space:

class Solution {
public:
  static const int MAX_PENALTY = 1e9;

  static int minimumSize(const std::vector<int> &nums, int max_operations) {
    int left = 1, right = MAX_PENALTY;
    while (left < right) {
      const auto middle = left + (right - left) / 2;
      long long ops = 0;
      for (auto num : nums) {
        ops += num / middle - (num % middle == 0);
      }
      ops > max_operations ? left = middle + 1 : right = middle;
    }
    return left;
  }
};
