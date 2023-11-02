#pragma once

#include <algorithm>
#include <vector>

// Time:
// Space:

class Solution {
public:
  static std::vector<bool> kidsWithCandies(const std::vector<int> &candies,
                                           int extraCandies) {
    const auto max_candies = *std::max_element(candies.begin(), candies.end());
    std::vector<bool> ans(candies.size(), false);
    for (size_t i = 0; i < candies.size(); ++i) {
      if (candies[i] + extraCandies >= max_candies) {
        ans[i] = true;
      }
    }
    return ans;
  }
};