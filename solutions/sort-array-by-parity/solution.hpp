#pragma once

#include <algorithm>
#include <vector>

// Time:
// Space:

class Solution {
public:
  static std::vector<int> sortArrayByParity(std::vector<int> nums) {
    std::partition(nums.begin(), nums.end(), [](int a) { return a % 2 == 0; });
    return nums;
  }
};
