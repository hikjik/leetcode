#pragma once

#include <algorithm>
#include <vector>

/*
  27. Remove Element
  https://leetcode.com/problems/remove-element/
  Difficulty: Easy
  Tags: Array, Two Pointers
  Time:
  Space:
*/

class Solution {
public:
  static int removeElement(std::vector<int> &nums, int val) {
    int left = 0, right = nums.size();
    while (left < right) {
      if (nums[left] == val) {
        std::swap(nums[left], nums[--right]);
      } else {
        left++;
      }
    }
    return right;
  }

private:
  static int stl(std::vector<int> &nums, int val) {
    return std::distance(nums.begin(),
                         std::remove(nums.begin(), nums.end(), val));
  }
};
