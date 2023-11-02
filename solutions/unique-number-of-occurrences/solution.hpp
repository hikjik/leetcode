#pragma once

#include <unordered_map>
#include <unordered_set>
#include <vector>

// Time:
// Space:

class Solution {
public:
  static bool uniqueOccurrences(const std::vector<int> &arr) {
    std::unordered_map<int, int> map;
    for (auto a : arr) {
      ++map[a];
    }
    std::unordered_set<int> set;
    for (const auto &[a, f] : map) {
      if (set.count(f)) {
        return false;
      }
      set.insert(f);
    }
    return true;
  }
};
