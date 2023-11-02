#pragma once

#include <algorithm>
#include <vector>

// Time:
// Space:

class Solution {
public:
  static int maxOperations(std::vector<int> nums, int k) {
    std::sort(nums.begin(), nums.end());
    int cnt = 0;
    int left = 0, right = nums.size() - 1;
    while (left < right) {
      if (const int sum = nums[left] + nums[right]; sum == k) {
        ++cnt;
        ++left, --right;
      } else if (sum < k) {
        ++left;
      } else {
        --right;
      }
    }
    return cnt;
  }
};
