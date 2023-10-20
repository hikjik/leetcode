#pragma once

#include <numeric>
#include <unordered_map>
#include <vector>

class Solution {
public:
  static bool hasGroupsSizeX(const std::vector<int> &deck) {
    std::unordered_map<int, int> counter;
    for (auto a : deck) {
      ++counter[a];
    }

    int gcd = counter[deck[0]];
    for (const auto &[_, f] : counter) {
      gcd = std::gcd(gcd, f);
    }
    return gcd > 1;
  }
};
