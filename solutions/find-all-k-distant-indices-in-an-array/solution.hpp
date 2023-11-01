#pragma once

#include <algorithm>
#include <vector>

/*
  2200. Find All K-Distant Indices in an Array
  https://leetcode.com/problems/find-all-k-distant-indices-in-an-array/
  Difficulty: Easy
  Tags: Array
  Time:
  Space:
*/

class Solution {
public:
  static std::vector<int> findKDistantIndices(const std::vector<int> &nums,
                                              int key, int k) {
    std::vector<int> ans;
    auto cnt = std::count(nums.begin(), nums.begin() + k, key);
    for (int i = 0; i < std::ssize(nums); ++i) {
      if (i + k < std::ssize(nums)) {
        cnt += nums[i + k] == key;
      }
      if (cnt) {
        ans.push_back(i);
      }
      if (i >= k) {
        cnt -= nums[i - k] == key;
      }
    }
    return ans;
  }
};
