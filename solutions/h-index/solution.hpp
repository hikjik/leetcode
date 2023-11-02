#pragma once

#include <algorithm>
#include <vector>

// Time:
// Space:

class Solution {
public:
  static int hIndex(std::vector<int> citations) {
    int n = citations.size();
    std::sort(citations.begin(), citations.end());

    int left = 0, right = n;
    while (left < right) {
      const auto middle = left + (right - left) / 2;
      if (citations[middle] >= n - middle) {
        right = middle;
      } else {
        left = middle + 1;
      }
    }
    return n - left;
  }
};
