#pragma once

#include <vector>

// Time:
// Space:

class Solution {
public:
  static int findLengthOfShortestSubarray(const std::vector<int> &arr) {
    int n = arr.size();

    int left = 0;
    while (left + 1 < n && arr[left] <= arr[left + 1]) {
      ++left;
    }

    int right = n - 1;
    while (right > 0 && arr[right] >= arr[right - 1]) {
      --right;
    }
    if (right == 0) {
      return 0;
    }

    int length = std::min(right, n - left - 1);

    for (int i = 0; i <= left; ++i) {
      while (right < n && arr[i] > arr[right]) {
        ++right;
      }
      if (right < n) {
        length = std::min(length, right - i - 1);
      }
    }

    return length;
  }
};
