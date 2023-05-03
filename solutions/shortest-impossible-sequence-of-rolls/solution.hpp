#pragma once

#include <unordered_set>
#include <vector>

class Solution {
public:
  static int shortestSequence(const std::vector<int> &rolls, size_t k) {
    std::unordered_set<int> seen;
    int min_length = 1;
    for (auto roll : rolls) {
      seen.insert(roll);
      if (seen.size() == k) {
        seen.clear();
        ++min_length;
      }
    }
    return min_length;
  }
};
