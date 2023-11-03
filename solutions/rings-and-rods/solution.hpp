#pragma once

#include <array>
#include <string>

// Time:
// Space:

class Solution {
public:
  static int countPoints(std::string rings) {
    std::array<int, 10> rods{};
    for (size_t i = 0; i < rings.size(); i += 2) {
      const auto color = rings[i] == 'R' ? 1 : rings[i] == 'B' ? 2 : 4;
      rods[rings[i + 1] - '0'] |= color;
    }
    return std::count(rods.begin(), rods.end(), 7);
  }
};
