#pragma once

#include <string>
#include <unordered_map>

class Solution {
public:
  static bool areOccurrencesEqual(std::string s) {
    std::unordered_map<char, int> counter;
    for (auto c : s) {
      ++counter[c];
    }
    return std::all_of(counter.begin(), counter.end(), [&](const auto &item) {
      return item.second == counter.begin()->second;
    });
  }
};
