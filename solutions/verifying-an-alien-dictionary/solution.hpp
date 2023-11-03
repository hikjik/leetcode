#pragma once

#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>

// Time:
// Space:

class Solution {
public:
  static bool isAlienSorted(const std::vector<std::string> &words,
                            std::string order) {
    std::unordered_map<char, size_t> positions;
    for (size_t i = 0; i < order.size(); ++i) {
      positions[order[i]] = i;
    }

    for (size_t i = 1; i < words.size(); ++i) {
      if (!less(words[i - 1], words[i], positions)) {
        return false;
      }
    }
    return true;
  }

private:
  static bool less(const std::string &lhs, const std::string &rhs,
                   const std::unordered_map<char, size_t> &positions) {
    for (size_t i = 0; i < std::min(lhs.size(), rhs.size()); ++i) {
      if (lhs[i] != rhs[i]) {
        return positions.at(lhs[i]) < positions.at(rhs[i]);
      }
    }

    return lhs.size() <= rhs.size();
  }
};
