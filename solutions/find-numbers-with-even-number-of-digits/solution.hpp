#pragma once

#include <algorithm>
#include <vector>

// Time:
// Space:

class Solution {
public:
  static int findNumbers(const std::vector<int> &nums) {
    return std::count_if(nums.begin(), nums.end(), [](int n) {
      return std::to_string(n).size() % 2 == 0;
    });
  }
};
