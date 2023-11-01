#pragma once

#include <algorithm>
#include <vector>

/*
  1460. Make Two Arrays Equal by Reversing Subarrays
  https://leetcode.com/problems/make-two-arrays-equal-by-reversing-subarrays/
  Difficulty: Easy
  Tags: Array, Hash Table, Sorting
  Time:
  Space:
*/

class Solution {
public:
  static bool canBeEqual(std::vector<int> target, std::vector<int> arr) {
    std::sort(target.begin(), target.end());
    std::sort(arr.begin(), arr.end());
    return target == arr;
  }
};
