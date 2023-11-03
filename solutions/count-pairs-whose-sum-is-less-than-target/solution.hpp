#pragma once

#include <algorithm>
#include <vector>

// Time:
// Space:

class Solution {
public:
  static int countPairs(std::vector<int> nums, int target) {
    std::sort(nums.begin(), nums.end());

    int cnt = 0;
    for (auto l = nums.begin(), r = --nums.end(); l != r;) {
      if (*l + *r < target) {
        cnt += r - l;
        ++l;
      } else {
        --r;
      }
    }
    return cnt;
  }
};
