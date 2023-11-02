#pragma once

#include <algorithm>
#include <vector>

// Time:
// Space:

class Solution {
public:
  static bool canMakeArithmeticProgression(std::vector<int> arr) {
    std::sort(arr.begin(), arr.end());
    for (size_t i = 2; i < arr.size(); ++i) {
      if (arr[i - 1] - arr[i - 2] != arr[i] - arr[i - 1]) {
        return false;
      }
    }
    return true;
  }
};
