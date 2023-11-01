#pragma once

#include <algorithm>
#include <vector>

/*
  1287. Element Appearing More Than 25% In Sorted Array
  https://leetcode.com/problems/element-appearing-more-than-25-in-sorted-array/
  Difficulty: Easy
  Tags: Array
  Time:
  Space:
*/

class Solution {
public:
  static int findSpecialInteger(const std::vector<int> &arr) {
    const int n = arr.size();
    for (int i = 0; i < n; i += n / 4) {
      auto [first, last] = std::equal_range(arr.begin(), arr.end(), arr[i]);
      if (std::distance(first, last) > n / 4) {
        return arr[i];
      }
    }
    throw;
  }
};
