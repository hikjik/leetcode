#pragma once

#include <string>
#include <vector>

class Solution {
public:
  static bool makeEqual(const std::vector<std::string> &words) {
    std::vector<int> counter(26);
    for (const auto &word : words) {
      for (auto c : word) {
        ++counter[c - 'a'];
      }
    }
    return std::all_of(counter.begin(), counter.end(), [&](auto frequency) {
      return frequency % words.size() == 0;
    });
  }
};
