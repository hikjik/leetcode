#pragma once

#include <cmath>

class Solution {
public:
  static int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
    const auto attempts = minutesToTest / minutesToDie;
    return std::ceil(std::log2(buckets) / std::log2(attempts + 1));
  }
};
