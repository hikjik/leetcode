#pragma once

#include <algorithm>
#include <climits>
#include <vector>

// Time:
// Space:

class Solution {
public:
  static int minSubArrayLen(int target, const std::vector<int> &nums) {
    int n = nums.size();

    int min_len = INT_MAX;
    int sum = 0;
    for (int left = 0, right = 0; right < n; ++right) {
      sum += nums[right];
      while (sum >= target) {
        min_len = std::min(min_len, right - left + 1);
        sum -= nums[left++];
      }
    }

    return min_len == INT_MAX ? 0 : min_len;
  }
};
