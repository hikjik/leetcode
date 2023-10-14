#pragma once

#include <vector>

class Solution {
public:
  static constexpr int kMaxValue = 200;

  static bool isGood(const std::vector<int> &nums) {
    const int n = nums.size() - 1;

    std::vector<int> counter(kMaxValue + 1);
    for (auto a : nums) {
      ++counter[a];
    }

    for (int i = 1; i < n; ++i) {
      if (counter[i] != 1) {
        return false;
      }
    }
    return counter[n] == 2;
  }
};
