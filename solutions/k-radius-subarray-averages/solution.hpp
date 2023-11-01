#pragma once

#include <vector>

/*
  2090. K Radius Subarray Averages
  https://leetcode.com/problems/k-radius-subarray-averages/
  Difficulty: Medium
  Tags: Array, Sliding Window
  Time:
  Space:
*/

class Solution {
public:
  static std::vector<int> getAverages(const std::vector<int> &nums, int k) {
    const int n = nums.size();
    const int window_size = 2 * k + 1;

    std::vector<int> averages(n, -1);
    long long sum = 0;

    for (int i = 0; i < n; ++i) {
      sum += nums[i];

      if (i >= window_size - 1) {
        averages[i - k] = sum / window_size;
        sum -= nums[i - window_size + 1];
      }
    }

    return averages;
  }
};
