#pragma once

#include <algorithm>
#include <vector>

/*
  215. Kth Largest Element in an Array
  https://leetcode.com/problems/kth-largest-element-in-an-array/
  Difficulty: Medium
  Tags: Array, Divide and Conquer, Sorting, Heap (Priority Queue), Quickselect
  Time:
  Space:
*/

class Solution {
public:
  static int findKthLargest(std::vector<int> nums, int k) {
    return stl(nums, k);
  }

private:
  static int stl(std::vector<int> &nums, int k) {
    std::nth_element(nums.begin(), nums.begin() + k - 1, nums.end(),
                     std::greater{});
    return nums[k - 1];
  }
};
