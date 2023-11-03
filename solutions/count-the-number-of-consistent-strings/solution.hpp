#pragma once

#include <ranges>
#include <string>
#include <unordered_set>
#include <vector>

// Time:
// Space:

class Solution {
public:
  static int countConsistentStrings(std::string allowed,
                                    const std::vector<std::string> &words) {
    std::unordered_set<char> set(allowed.begin(), allowed.end());
    return std::ranges::count_if(words, [&](const auto &word) {
      return std::ranges::all_of(word, [&](char c) { return set.contains(c); });
    });
  }
};
