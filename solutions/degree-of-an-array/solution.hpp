#pragma once

#include <unordered_map>
#include <vector>

/*
  697. Degree of an Array
  https://leetcode.com/problems/degree-of-an-array/
  Difficulty: Easy
  Tags: Array, Hash Table
  Time:
  Space:
*/

class Solution {
public:
  static int findShortestSubArray(const std::vector<int> &nums) {
    std::unordered_map<int, int> left, right;
    std::unordered_map<int, int> counter;
    int degree = 0;
    for (int i = 0; i < std::ssize(nums); ++i) {
      if (!left.contains(nums[i])) {
        left[nums[i]] = i;
      }
      right[nums[i]] = i;
      degree = std::max(degree, ++counter[nums[i]]);
    }

    int ans = nums.size();
    for (const auto &[a, frequency] : counter) {
      if (frequency == degree) {
        ans = std::min(ans, right[a] - left[a] + 1);
      }
    }
    return ans;
  }
};
