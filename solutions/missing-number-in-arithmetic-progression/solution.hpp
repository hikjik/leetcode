#pragma once

#include <vector>

// Time: O(N)
// Space: O(1)

class Solution {
public:
  static int missingNumber(const std::vector<int> &arr) {
    if (arr.front() == arr.back()) {
      return arr.front();
    }

    const auto d = (arr.back() - arr.front()) / std::ssize(arr);
    for (int a = arr.front(); auto b : arr) {
      if (a != b) {
        return a;
      }
      a += d;
    }
    throw;
  }
};
