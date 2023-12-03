#pragma once

#include <ranges>
#include <vector>

// Time: O(logN)
// Space: O(1)

class Solution {
public:
  static int minPatches(const std::vector<int> &nums, int n) {
    int ans = 0;
    int j = 0;
    for (long long sum = 1; sum <= n;) {
      if (j == ssize(nums) || nums[j] > sum) {
        ++ans;
        sum += sum;
      } else {
        sum += nums[j++];
      }
    }
    return ans;
  }
};
