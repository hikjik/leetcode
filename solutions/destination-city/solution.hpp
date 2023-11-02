#pragma once

#include <string>
#include <unordered_set>
#include <vector>

// Time:
// Space:

class Solution {
public:
  static std::string
  destCity(const std::vector<std::vector<std::string>> &paths) {
    std::unordered_set<std::string> set;
    for (const auto &path : paths) {
      set.insert(path[0]);
    }
    for (const auto &path : paths) {
      if (!set.contains(path[1])) {
        return path[1];
      }
    }
    throw;
  }
};
