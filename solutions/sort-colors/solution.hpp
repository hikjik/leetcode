#pragma once

#include <vector>

/*
  75. Sort Colors
  https://leetcode.com/problems/sort-colors/
  Difficulty: Medium
  Tags: Array, Two Pointers, Sorting
  Time:
  Space:
*/

class Solution {
public:
  static void sortColors(std::vector<int> &nums) {
    int zero = 0, two = nums.size() - 1;
    for (int i = 0; i <= two;) {
      switch (nums[i]) {
      case 0:
        std::swap(nums[i++], nums[zero++]);
        break;
      case 1:
        i++;
        break;
      case 2:
        std::swap(nums[i], nums[two--]);
        break;
      default:
        throw;
      }
    }
  }
};
