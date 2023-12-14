#pragma once

#include <numeric>
#include <ranges>
#include <vector>

// Time: O(NlogN)
// Space: O(N)

class Solution {
public:
  static int maximumBags(const std::vector<int> &capacity,
                         const std::vector<int> &rocks, int additionalRocks) {
    const int n = rocks.size();
    std::vector<int> diff(n);
    for (int i = 0; i < n; ++i) {
      diff[i] = capacity[i] - rocks[i];
    }
    std::ranges::sort(diff);

    for (int i = 0; i < n; ++i) {
      if (diff[i] > additionalRocks) {
        return i;
      }
      additionalRocks -= diff[i];
    }
    return n;
  }
};
