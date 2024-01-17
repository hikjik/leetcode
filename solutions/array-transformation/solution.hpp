#pragma once

#include <utility>
#include <vector>

// Time: O(N^2)
// Space: O(N)

class Solution {
public:
  static std::vector<int> transformArray(std::vector<int> arr) {
    bool change = false;
    do {
      change = false;
      int prev = arr[0];
      for (int i = 1; i + 1 < std::ssize(arr); ++i) {
        if (prev < arr[i] && arr[i] > arr[i + 1]) {
          prev = std::exchange(arr[i], arr[i] - 1);
          change = true;
        } else if (prev > arr[i] && arr[i] < arr[i + 1]) {
          prev = std::exchange(arr[i], arr[i] + 1);
          change = true;
        } else {
          prev = arr[i];
        }
      }
    } while (change);
    return arr;
  }
};
