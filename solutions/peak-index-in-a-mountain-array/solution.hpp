#pragma once

#include <vector>

class Solution {
public:
  static int peakIndexInMountainArray(const std::vector<int> &arr) {
    int left = 0, right = arr.size() - 1;
    while (left < right) {
      const auto middle = left + (right - left) / 2;
      arr[middle] < arr[middle + 1] ? left = middle + 1 : right = middle;
    }
    return left;
  }
};
