#pragma once

#include <ranges>
#include <vector>

// Time: O(N)
// Space: O(1)

class Solution {
public:
  static int maxDistToClosest(const std::vector<int> &seats) {
    const int n = seats.size();

    int ans = 0;
    int l = -1;
    for (int r = 0; r < n; ++r) {
      if (seats[r]) {
        ans = l == -1 ? r : std::max(ans, (r - l) >> 1);
        l = r;
      }
    }
    return std::max(ans, n - l - 1);
  }
};
