#pragma once

#include <vector>

/*
  2348. Number of Zero-Filled Subarrays
  https://leetcode.com/problems/number-of-zero-filled-subarrays/
  Difficulty: Medium
  Tags: Array, Math
  Time:
  Space:
*/

class Solution {
public:
  static long long zeroFilledSubarray(const std::vector<int> &nums) {
    long long res = 0, cnt = 0;
    for (auto num : nums) {
      if (!num) {
        cnt++;
      } else {
        res += (cnt + 1) * cnt / 2;
        cnt = 0;
      }
    }
    return res + (cnt + 1) * cnt / 2;
  }
};
