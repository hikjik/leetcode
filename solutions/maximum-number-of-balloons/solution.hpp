#pragma once

#include <climits>
#include <string>
#include <unordered_map>

// Time:
// Space:

class Solution {
public:
  static int maxNumberOfBalloons(std::string text) {
    auto map = buildMap(text);
    int ans = INT_MAX;
    for (const auto &[c, f] : buildMap("balloon")) {
      ans = std::min(ans, map[c] / f);
    }
    return ans;
  }

  static std::unordered_map<char, int> buildMap(std::string str) {
    std::unordered_map<char, int> map;
    for (auto c : str) {
      ++map[c];
    }
    return map;
  }
};
