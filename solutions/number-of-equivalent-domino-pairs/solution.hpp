#pragma once

#include <unordered_map>
#include <vector>

// Time:
// Space:

class Solution {
public:
  static int
  numEquivDominoPairs(const std::vector<std::vector<int>> &dominoes) {
    std::unordered_map<int, int> map;
    int ans = 0;
    for (const auto &domino : dominoes) {
      ans += map[1 << domino[0] | 1 << domino[1]]++;
    }
    return ans;
  }
};
