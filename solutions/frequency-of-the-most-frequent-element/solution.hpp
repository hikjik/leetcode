#pragma once

#include <algorithm>
#include <vector>

// Time:
// Space:

class Solution {
public:
  static int maxFrequency(std::vector<int> nums, int k) {
    int n = nums.size();
    std::sort(nums.begin(), nums.end());

    int max_freq = 1;
    int sum = 0;
    for (int i = 0, j = 0; j < n; ++j) {
      sum += nums[j];
      while (sum + k < 1LL * nums[j] * (j - i + 1)) {
        sum -= nums[i++];
      }
      max_freq = std::max(max_freq, j - i + 1);
    }
    return max_freq;
  }
};
