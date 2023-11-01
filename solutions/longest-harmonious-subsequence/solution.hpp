#pragma once

#include <unordered_map>
#include <vector>

/*
  594. Longest Harmonious Subsequence
  https://leetcode.com/problems/longest-harmonious-subsequence/
  Difficulty: Easy
  Tags: Array, Hash Table, Sorting
  Time:
  Space:
*/

class Solution {
public:
  static int findLHS(const std::vector<int> &nums) {
    std::unordered_map<int, int> counter;
    for (auto a : nums) {
      ++counter[a];
    }

    int ans = 0;
    for (const auto &[a, f] : counter) {
      if (auto it = counter.find(a + 1); it != counter.end()) {
        ans = std::max(ans, f + it->second);
      }
    }
    return ans;
  }
};
