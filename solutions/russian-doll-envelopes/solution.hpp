#pragma once

#include <numeric>
#include <ranges>
#include <vector>

// Time: O(NlogN)
// Space: O(N)

class Solution {
public:
  static int maxEnvelopes(const std::vector<std::vector<int>> &envelopes) {
    std::vector<int> idx(envelopes.size());
    std::iota(idx.begin(), idx.end(), 0);
    std::ranges::sort(idx, [&](int i, int j) {
      return std::tie(envelopes[i][0], envelopes[j][1]) <
             std::tie(envelopes[j][0], envelopes[i][1]);
    });

    std::vector<int> dp;
    for (int k : idx) {
      auto it = std::ranges::lower_bound(dp, k, [&](int i, int j) {
        return envelopes[i][1] < envelopes[j][1];
      });
      if (it == dp.end()) {
        dp.push_back(k);
      } else {
        *it = k;
      }
    }
    return dp.size();
  }
};
