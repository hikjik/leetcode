#pragma once

#include <algorithm>
#include <numeric>
#include <vector>

/*
  2389. Longest Subsequence With Limited Sum
  https://leetcode.com/problems/longest-subsequence-with-limited-sum/
  Difficulty: Easy
  Tags: Array, Binary Search, Greedy, Sorting, Prefix Sum
  Time:
  Space:
*/

class Solution {
public:
  static std::vector<int> answerQueries(std::vector<int> nums,
                                        const std::vector<int> &queries) {
    std::sort(nums.begin(), nums.end());
    std::partial_sum(nums.cbegin(), nums.cend(), nums.begin());
    std::vector<int> ans;
    for (auto query : queries) {
      ans.push_back(std::upper_bound(nums.cbegin(), nums.cend(), query) -
                    nums.cbegin());
    }
    return ans;
  }
};
