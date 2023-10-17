#pragma once

#include <map>
#include <set>
#include <string>
#include <vector>

class Solution {
public:
  static std::string bestHand(const std::vector<int> &ranks,
                              const std::vector<char> &suits) {
    if (std::set(suits.begin(), suits.end()).size() == 1) {
      return "Flush";
    }

    std::map<int, int> count;
    int max = 0;
    for (auto r : ranks) {
      max = std::max(max, ++count[r]);
    }
    if (max > 2) {
      return "Three of a Kind";
    }
    if (max > 1) {
      return "Pair";
    }
    return "High Card";
  }
};
