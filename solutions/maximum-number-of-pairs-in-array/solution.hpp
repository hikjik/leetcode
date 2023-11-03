#pragma once

#include <unordered_map>
#include <vector>

// Time:
// Space:

class Solution {
public:
  static std::vector<int> numberOfPairs(const std::vector<int> &nums) {
    std::unordered_map<int, int> counter;
    for (auto n : nums) {
      ++counter[n];
    }

    int pairs = 0, leftover = 0;
    for (const auto [_, f] : counter) {
      pairs += f / 2;
      leftover += f % 2;
    }
    return {pairs, leftover};
  }
};
