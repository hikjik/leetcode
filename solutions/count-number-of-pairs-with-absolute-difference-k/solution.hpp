#pragma once

#include <unordered_map>
#include <vector>

/*
  2006. Count Number of Pairs With Absolute Difference K
  https://leetcode.com/problems/count-number-of-pairs-with-absolute-difference-k/
  Difficulty: Easy
  Tags: Array, Hash Table, Counting
  Time:
  Space:
*/

class Solution {
public:
  static int countKDifference(const std::vector<int> &nums, int k) {
    std::unordered_map<int, int> map;
    int cnt = 0;
    for (auto a : nums) {
      cnt += map[a - k] + map[a + k];
      ++map[a];
    }
    return cnt;
  }
};
