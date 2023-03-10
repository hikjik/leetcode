#pragma once

#include <algorithm>
#include <vector>

class Solution {
public:
  static int triangleNumber(std::vector<int> nums) {
    std::sort(nums.begin(), nums.end());

    int cnt = 0;
    for (int k = nums.size() - 1; k >= 0; --k) {
      int i = 0, j = k - 1;
      while (i < j) {
        if (nums[i] + nums[j] > nums[k]) {
          cnt += j - i;
          --j;
        } else {
          ++i;
        }
      }
    }
    return cnt;
  }
};
