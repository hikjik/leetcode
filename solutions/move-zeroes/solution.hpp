#pragma once

#include <algorithm>
#include <vector>

class Solution {
public:
  static void moveZeroes(std::vector<int> &nums) {
    auto it = nums.begin();
    for (auto num : nums) {
      if (num) {
        *it++ = num;
      }
    }
    std::fill(it, nums.end(), 0);
  }
};
