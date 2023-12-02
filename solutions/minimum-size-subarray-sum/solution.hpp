#pragma once

#include <algorithm>
#include <climits>
#include <vector>

// Time: O(N)
// Space: O(1)

class Solution {
public:
  static int minSubArrayLen(int target, const std::vector<int> &nums) {
    int ans = INT_MAX;
    int sum = 0;
    for (int left = 0, right = 0; right < std::ssize(nums); ++right) {
      sum += nums[right];
      while (sum >= target) {
        ans = std::min(ans, right - left + 1);
        sum -= nums[left++];
      }
    }
    return ans == INT_MAX ? 0 : ans;
  }
};
