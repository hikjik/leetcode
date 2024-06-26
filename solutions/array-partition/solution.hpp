#pragma once

#include <algorithm>
#include <vector>

// Time:
// Space:

class Solution {
public:
  static int arrayPairSum(std::vector<int> nums) {
    std::sort(nums.begin(), nums.end());
    int sum = 0;
    for (int i = 0; i < std::ssize(nums); i += 2) {
      sum += nums[i];
    }
    return sum;
  }
};
