#pragma once

#include <unordered_set>
#include <vector>

// Time:
// Space:

class Solution {
public:
  static int distributeCandies(const std::vector<int> &candyType) {
    std::unordered_set<int> types(candyType.begin(), candyType.end());
    return std::min(types.size(), candyType.size() / 2);
  }
};
