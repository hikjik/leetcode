#pragma once

#include <numeric>
#include <ranges>
#include <vector>

// Time: O(N)
// Space: O(N)

namespace sorting {

// Time: O(NlogN)
// Space: O(N)
class Solution {
public:
  static int eliminateMaximum(const std::vector<int> &dist,
                              const std::vector<int> &speed) {
    const int n = dist.size();

    std::vector<int> arrival(n);
    for (int i = 0; i < n; ++i) {
      arrival[i] = (dist[i] + speed[i] - 1) / speed[i];
    }
    std::ranges::sort(arrival);

    for (int i = 0; i < n; ++i) {
      if (i >= arrival[i]) {
        return i;
      }
    }
    return n;
  }
};

} // namespace sorting

namespace counting {

// Time: O(N)
// Space: O(N)
class Solution {
public:
  static int eliminateMaximum(const std::vector<int> &dist,
                              const std::vector<int> &speed) {
    const int n = dist.size();

    std::vector<int> counter(n);
    for (int i = 0; i < n; ++i) {
      const auto arrival = (dist[i] + speed[i] - 1) / speed[i];
      if (arrival < n) {
        ++counter[arrival];
      }
    }
    std::partial_sum(counter.cbegin(), counter.cend(), counter.begin());

    for (int i = 0; i < n; ++i) {
      if (counter[i] > i) {
        return i;
      }
    }
    return n;
  }
};

} // namespace counting
