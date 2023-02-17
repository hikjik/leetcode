#pragma once

#include <vector>

class Solution {
public:
  static int peakIndexInMountainArray(const std::vector<int> &arr) {
    int left = 0;
    int right = arr.size() - 1;
    while (left < right) {
      const int middle = left + (right - left) / 2;
      if (arr[middle - 1] < arr[middle] && arr[middle] > arr[middle + 1]) {
        return middle;
      } else if (arr[middle - 1] < arr[middle]) {
        left = middle + 1;
      } else {
        right = middle;
      }
    }
    return left;
  }
};