#pragma once

#include <vector>

/*
  1526. Minimum Number of Increments on Subarrays to Form a Target Array
  https://leetcode.com/problems/minimum-number-of-increments-on-subarrays-to-form-a-target-array/
  Difficulty: Hard
  Tags: Array, Dynamic Programming, Stack, Greedy, Monotonic Stack
  Time:
  Space:
*/

class Solution {
public:
  static int minNumberOperations(const std::vector<int> &target) {
    int cnt = target.front();
    for (size_t i = 1; i < target.size(); ++i) {
      if (target[i - 1] < target[i]) {
        cnt += target[i] - target[i - 1];
      }
    }
    return cnt;
  }
};