#pragma once

#include <vector>

/*
  167. Two Sum II - Input Array Is Sorted
  https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/
  Difficulty: Medium
  Tags: Array, Two Pointers, Binary Search
  Time:
  Space:
*/

class Solution {
public:
  static std::vector<int> twoSum(const std::vector<int> &numbers, int target) {
    int left = 0;
    int right = numbers.size() - 1;
    while (left < right) {
      int sum = numbers[left] + numbers[right];
      if (sum == target) {
        return {left + 1, right + 1};
      }

      if (sum > target) {
        right--;
      } else {
        left++;
      }
    }
    return {};
  }
};
