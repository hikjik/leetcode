#pragma once

#include <algorithm>
#include <numeric>
#include <vector>

/*
  1658. Minimum Operations to Reduce X to Zero
  https://leetcode.com/problems/minimum-operations-to-reduce-x-to-zero/
  Difficulty: Medium
  Tags: Array, Hash Table, Binary Search, Sliding Window, Prefix Sum
  Time:
  Space:
*/

class Solution {
public:
  static int minOperations(const std::vector<int> &nums, int x) {
    const auto sum = std::accumulate(nums.begin(), nums.end(), 0);
    const auto length = maxSubArrayLen(nums, sum - x);
    return length == -1 ? -1 : nums.size() - length;
  }

private:
  static int maxSubArrayLen(const std::vector<int> &nums, int target_sum) {
    const int n = nums.size();
    int window_sum = 0;
    int length = -1;
    for (int l = 0, r = 0; r < n; ++r) {
      window_sum += nums[r];
      while (window_sum > target_sum && l <= r) {
        window_sum -= nums[l++];
      }
      if (window_sum == target_sum) {
        length = std::max(length, r - l + 1);
      }
    }
    return length;
  }
};
