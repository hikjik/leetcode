#pragma once

#include <vector>

// Time:
// Space:

class Solution {
public:
  static int minCostToMoveChips(const std::vector<int> &position) {
    const int even = std::count_if(position.begin(), position.end(),
                                   [](int a) { return a % 2 == 0; });
    const int odd = position.size() - even;
    return std::min(even, odd);
  }
};
