#pragma once

#include <vector>

/*
  1217. Minimum Cost to Move Chips to The Same Position
  https://leetcode.com/problems/minimum-cost-to-move-chips-to-the-same-position/
  Difficulty: Easy
  Tags: Array, Math, Greedy
  Time:
  Space:
*/

class Solution {
public:
  static int minCostToMoveChips(const std::vector<int> &position) {
    const int even = std::count_if(position.begin(), position.end(),
                                   [](int a) { return a % 2 == 0; });
    const int odd = position.size() - even;
    return std::min(even, odd);
  }
};
