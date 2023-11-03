#pragma once

#include <unordered_set>
#include <vector>

// Time:
// Space:

class Solution {
public:
  static int oddCells(int m, int n,
                      const std::vector<std::vector<int>> &indices) {
    std::vector<std::unordered_set<int>> sets(2);
    for (const auto &index : indices) {
      for (int i = 0; i < 2; ++i) {
        if (sets[i].contains(index[i])) {
          sets[i].erase(index[i]);
        } else {
          sets[i].insert(index[i]);
        }
      }
    }
    return sets[0].size() * (n - sets[1].size()) +
           sets[1].size() * (m - sets[0].size());
  }
};
