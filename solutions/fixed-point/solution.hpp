#pragma once

#include <vector>

// Time: O(logN)
// Space: O(1)

class Solution {
public:
  static int fixedPoint(const std::vector<int> &arr) {
    int l = 0, r = arr.size() - 1;
    while (l < r) {
      const auto m = l + (r - l) / 2;
      arr[m] < m ? l = m + 1 : r = m;
    }
    return arr[l] == l ? l : -1;
  }
};
