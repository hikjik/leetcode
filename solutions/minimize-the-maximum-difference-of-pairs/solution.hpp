#pragma once

#include <algorithm>
#include <vector>

/*
  2616. Minimize the Maximum Difference of Pairs
  https://leetcode.com/problems/minimize-the-maximum-difference-of-pairs/
  Difficulty: Medium
  Tags: Array, Binary Search, Greedy
  Time:
  Space:
*/

class Solution {
public:
  static int minimizeMax(std::vector<int> nums, int p) {
    std::sort(nums.begin(), nums.end());
    int left = 0, right = nums.back() - nums.front();
    while (left < right) {
      const auto middle = left + (right - left) / 2;
      countValidPairs(nums, middle) >= p ? right = middle : left = middle + 1;
    }
    return left;
  }

private:
  static int countValidPairs(const std::vector<int> nums, int threshold) {
    int cnt = 0;
    for (size_t i = 0; i + 1 < nums.size(); ++i) {
      if (nums[i + 1] - nums[i] <= threshold) {
        ++cnt, ++i;
      }
    }
    return cnt;
  }
};
