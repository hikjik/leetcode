#pragma once

#include <algorithm>
#include <unordered_set>
#include <vector>

/*
  128. Longest Consecutive Sequence
  https://leetcode.com/problems/longest-consecutive-sequence/
  Difficulty: Medium
  Tags: Array, Hash Table, Union Find
  Time:
  Space:
*/

class Solution {
public:
  static int longestConsecutive(const std::vector<int> &nums) {
    std::unordered_set<int> set(nums.begin(), nums.end());
    int longest = 0;
    for (auto num : nums) {
      if (set.count(num - 1)) {
        continue;
      }

      int length = 1;
      while (set.count(num + 1)) {
        length++;
        num++;
      }
      longest = std::max(longest, length);
    }
    return longest;
  }
};
