#pragma once

#include <vector>

// Time: O(N)
// Space: O(1)

class Solution {
public:
  static std::vector<long long> minimumCosts(const std::vector<int> &regular,
                                             const std::vector<int> &express,
                                             int expressCost) {
    std::vector<long long> ans(regular.size());
    long long rCost = 0, eCost = expressCost;
    for (int i = 0; i < std::ssize(ans); ++i) {
      rCost = std::min(rCost, eCost) + regular[i];
      eCost = std::min(eCost + express[i], rCost + expressCost);
      ans[i] = std::min(rCost, eCost);
    }
    return ans;
  }
};
