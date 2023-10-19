#pragma once

#include <algorithm>
#include <string>
#include <unordered_set>

class Solution {
public:
  static int numJewelsInStones(std::string jewels, std::string stones) {
    std::unordered_set<char> set(jewels.begin(), jewels.end());
    return std::count_if(stones.begin(), stones.end(),
                         [&](char c) { return set.contains(c); });
  }
};
