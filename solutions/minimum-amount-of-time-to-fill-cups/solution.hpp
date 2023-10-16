#pragma once

#include <algorithm>
#include <numeric>
#include <vector>

class Solution {
public:
  static int fillCups(const std::vector<int> &amount) {
    const auto max = *std::max_element(amount.begin(), amount.end());
    const auto sum = std::accumulate(amount.begin(), amount.end(), 0);
    return std::max(max, (sum + 1) / 2);
  }
};
