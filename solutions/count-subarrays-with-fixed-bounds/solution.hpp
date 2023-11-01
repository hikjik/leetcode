#pragma once

#include <algorithm>
#include <vector>

/*
  2444. Count Subarrays With Fixed Bounds
  https://leetcode.com/problems/count-subarrays-with-fixed-bounds/
  Difficulty: Hard
  Tags: Array, Queue, Sliding Window, Monotonic Queue
  Time:
  Space:
*/

class Solution {
public:
  static long long countSubarrays(const std::vector<int> &nums, int minK,
                                  int maxK) {
    int n = nums.size();
    int minK_pos = -1, maxK_pos = -1;
    int out_bound_pos = -1;

    long long total = 0;
    for (int i = 0; i < n; ++i) {
      if (nums[i] < minK || nums[i] > maxK) {
        out_bound_pos = i;
      }
      if (nums[i] == minK) {
        minK_pos = i;
      }
      if (nums[i] == maxK) {
        maxK_pos = i;
      }
      total += std::max(0, std::min(minK_pos, maxK_pos) - out_bound_pos);
    }
    return total;
  }
};
