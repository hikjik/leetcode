#pragma once

#include <algorithm>
#include <vector>

class Solution {
public:
  static void nextPermutation(std::vector<int> &nums) {
    std::next_permutation(nums.begin(), nums.end());
  }
};
