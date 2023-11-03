#pragma once

#include <algorithm>
#include <vector>

// Time:
// Space:

class Solution {
public:
  static std::vector<int> successfulPairs(const std::vector<int> &spells,
                                          std::vector<int> potions,
                                          long long success) {
    std::sort(potions.begin(), potions.end());

    std::vector<int> pairs;
    pairs.reserve(spells.size());

    for (auto spell : spells) {
      auto potion = (success + spell - 1) / spell;
      auto lb = std::lower_bound(potions.begin(), potions.end(), potion);
      pairs.push_back(std::distance(lb, potions.end()));
    }

    return pairs;
  }
};
