#pragma once

#include <vector>

class Solution {
public:
  static int findKthPositive(const std::vector<int> &arr, int k) {
    int left = 0, right = arr.size();
    while (left < right) {
      auto middle = left + (right - left) / 2;
      if (arr[middle] - middle - 1 < k) {
        left = middle + 1;
      } else {
        right = middle;
      }
    }
    return k + left;
  }
};
