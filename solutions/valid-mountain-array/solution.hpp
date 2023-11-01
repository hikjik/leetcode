#pragma once

#include <algorithm>
#include <vector>

/*
  941. Valid Mountain Array
  https://leetcode.com/problems/valid-mountain-array/
  Difficulty: Easy
  Tags: Array
  Time:
  Space:
*/

class Solution {
public:
  static bool validMountainArray(const std::vector<int> &arr) {
    if (arr.size() < 3) {
      return false;
    }
    auto peak = std::max_element(std::next(arr.begin()), std::prev(arr.end()));
    for (auto it = arr.begin(); it != arr.end(); ++it) {
      if (it < peak && *it >= *std::next(it) ||
          it > peak && *it >= *std::prev(it)) {
        return false;
      }
    }
    return true;
  }
};
