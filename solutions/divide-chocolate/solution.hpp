#pragma once

#include <numeric>
#include <ranges>
#include <vector>

// M = sum(sweetness)
// Time: O(NlogM)
// Space: O(1)

class Solution {
public:
  static int maximizeSweetness(const std::vector<int> &sweetness, int k) {
    int left = std::ranges::min(sweetness);
    int right = std::accumulate(sweetness.begin(), sweetness.end(), 0);
    while (left < right) {
      const auto middle = left + (right - left + 1) / 2;
      int cnt = 0;
      for (int sum = 0; auto s : sweetness) {
        sum += s;
        if (sum >= middle) {
          ++cnt;
          sum = 0;
        }
      }
      cnt >= k + 1 ? left = middle : right = middle - 1;
    }
    return left;
  }
};
