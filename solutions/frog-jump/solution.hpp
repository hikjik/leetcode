#pragma once

#include <algorithm>
#include <vector>

/*
  403. Frog Jump
  https://leetcode.com/problems/frog-jump/
  Difficulty: Hard
  Tags: Array, Dynamic Programming
  Time:
  Space:
*/

class Solution {
public:
  static bool canCross(const std::vector<int> &stones) {
    std::vector dp(stones.size(), std::vector<char>(stones.size(), -1));
    return canCross(0, 0, stones, &dp);
  }

private:
  static bool canCross(size_t idx, int k, const std::vector<int> &stones,
                       std::vector<std::vector<char>> *dp) {
    if (idx + 1 == stones.size()) {
      return true;
    }

    auto &can_cross = (*dp)[idx][k];
    if (can_cross != -1) {
      return can_cross;
    }

    can_cross = false;
    for (int jump = std::max(0, k - 1); jump <= k + 1; ++jump) {
      const auto stone = stones[idx] + jump;
      auto it = std::lower_bound(stones.begin() + idx + 1, stones.end(), stone);
      if (it != stones.end() && *it == stone) {
        can_cross |= canCross(it - stones.begin(), jump, stones, dp);
      }
    }

    return can_cross;
  }
};
