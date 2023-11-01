#pragma once

#include <iterator>
#include <numeric>
#include <vector>

/*
  1712. Ways to Split Array Into Three Subarrays
  https://leetcode.com/problems/ways-to-split-array-into-three-subarrays/
  Difficulty: Medium
  Tags: Array, Two Pointers, Binary Search, Prefix Sum
  Time:
  Space:
*/

class Solution {
public:
  static const int kMod = 1e9 + 7;

  static int waysToSplit(const std::vector<int> &nums) {
    int n = nums.size();
    std::vector<int> ps(n);
    std::partial_sum(nums.begin(), nums.end(), ps.begin());

    int j = 0, k = 0;
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
      j = std::max(j, i + 1);
      while (j < n && ps[i] > ps[j] - ps[i]) {
        ++j;
      }
      k = std::max(k, j);
      while (k < n - 1 && ps[k] - ps[i] <= ps[n - 1] - ps[k]) {
        ++k;
      }
      cnt = (cnt - j + k) % kMod;
    }
    return cnt;
  }
};
