#pragma once

#include <vector>

/*
  2908. Minimum Sum of Mountain Triplets I
  https://leetcode.com/problems/minimum-sum-of-mountain-triplets-i/
  Difficulty: Easy
  Tags: Array
  Time:
  Space:
*/

class Solution {
public:
  static int minimumSum(const std::vector<int> &nums) {
    const int n = nums.size();

    std::vector<int> prefix_min(n, nums.front());
    for (int i = 1; i < n; ++i) {
      prefix_min[i] = std::min(prefix_min[i - 1], nums[i]);
    }
    std::vector<int> suffix_min(n, nums.back());
    for (int i = n - 2; i >= 0; --i) {
      suffix_min[i] = std::min(nums[i], suffix_min[i + 1]);
    }

    int ans = INT_MAX;
    for (int i = 1; i < n - 1; ++i) {
      if (prefix_min[i - 1] < nums[i] && nums[i] > suffix_min[i + 1]) {
        ans = std::min(ans, prefix_min[i - 1] + nums[i] + suffix_min[i + 1]);
      }
    }
    return ans == INT_MAX ? -1 : ans;
  }
};
