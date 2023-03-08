#pragma once

#include <algorithm>
#include <vector>

class Solution {
public:
  static int maxDistance(std::vector<int> positions, int m) {
    std::sort(positions.begin(), positions.end());

    int left = 1, right = 1e9;
    while (left < right) {
      const auto middle = left + (right - left + 1) / 2;

      int balls = 1;
      int prev = 0;
      for (size_t i = 1; i < positions.size(); ++i) {
        if (positions[i] - positions[prev] >= middle) {
          balls++;
          prev = i;
        }
      }

      balls < m ? right = middle - 1 : left = middle;
    }
    return left;
  }
};
