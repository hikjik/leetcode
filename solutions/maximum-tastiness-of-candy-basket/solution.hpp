#pragma once

#include <ranges>
#include <vector>

// N = price.size(), m = max(price),
// Time: O(NlogN+NlogM)
// Space: O(N)

class Solution {
public:
  static int maximumTastiness(std::vector<int> price, int k) {
    std::ranges::sort(price);

    int l = 0, r = price.back() - price.front() + 1;
    while (l < r) {
      const auto m = l + (r - l + 1) / 2;

      int cnt = 1;
      for (int i = 0, j = 1; j < std::ssize(price); ++j) {
        if (price[j] - price[i] >= m) {
          cnt++;
          i = j;
        }
      }

      cnt >= k ? l = m : r = m - 1;
    }
    return l;
  }
};
