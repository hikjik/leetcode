#pragma once

#include <unordered_map>
#include <vector>

/*
  2475. Number of Unequal Triplets in Array
  https://leetcode.com/problems/number-of-unequal-triplets-in-array/
  Difficulty: Easy
  Tags: Array, Hash Table
  Time:
  Space:
*/

class Solution {
public:
  static int unequalTriplets(const std::vector<int> &nums) {
    const int n = nums.size();

    std::unordered_map<int, int> frequencies;
    for (auto num : nums) {
      ++frequencies[num];
    }

    int cnt = 0;
    for (const auto &[_, f] : frequencies) {
      if (f >= 3) {
        cnt += f * (f - 1) * (f - 2) / 6;
      }
      if (f >= 2) {
        cnt += f * (f - 1) / 2 * (n - f);
      }
    }
    return n * (n - 1) * (n - 2) / 6 - cnt;
  }
};
