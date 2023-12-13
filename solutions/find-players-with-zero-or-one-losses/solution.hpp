#pragma once

#include <map>
#include <vector>

// Time: O(NlogN)
// Space: O(N)

class Solution {
public:
  static std::vector<std::vector<int>>
  findWinners(const std::vector<std::vector<int>> &matches) {
    std::map<int, int> map;
    for (const auto &match : matches) {
      const auto winner = match[0], loser = match[1];
      map[winner];
      ++map[loser];
    }

    std::vector<std::vector<int>> ans(2);
    for (const auto &[player, losses] : map) {
      if (losses < 2) {
        ans[losses].push_back(player);
      }
    }
    return ans;
  }
};
