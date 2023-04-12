#pragma once

#include <vector>

class Solution {
public:
  static int findLatestStep(const std::vector<int> &arr, int m) {
    const int n = arr.size();
    if (m == n) {
      return n;
    }

    std::vector<int> length(n + 2, 0);
    int step = -1;
    for (int i = 0; i < n; ++i) {
      const auto a = arr[i];
      const auto left = length[a - 1], right = length[a + 1];
      length[a - left] = length[a + right] = left + right + 1;
      if (left == m || right == m) {
        step = i;
      }
    }
    return step;
  }
};
