#pragma once

#include <numeric>
#include <vector>

// N = length
// M = updates.size()
// Time: O(N+M)
// Space: O(N)

class Solution {
public:
  static std::vector<int>
  getModifiedArray(int length, const std::vector<std::vector<int>> &updates) {
    std::vector<int> ps(length + 1);
    for (const auto &update : updates) {
      ps[update[0]] += update[2];
      ps[update[1] + 1] -= update[2];
    }
    std::partial_sum(ps.cbegin(), ps.cend(), ps.begin());
    ps.pop_back();
    return ps;
  }
};
