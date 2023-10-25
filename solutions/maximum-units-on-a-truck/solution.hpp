#pragma once

#include <ranges>
#include <vector>

class Solution {
public:
  static int maximumUnits(std::vector<std::vector<int>> boxTypes,
                          int truckSize) {
    std::ranges::sort(boxTypes, [](const auto &lhs, const auto &rhs) {
      return std::tie(lhs[1], lhs[0]) > std::tie(rhs[1], rhs[0]);
    });

    int ans = 0;
    for (const auto &box_type : boxTypes) {
      const auto size = std::min(truckSize, box_type[0]);
      ans += size * box_type[1];
      truckSize -= size;
    }
    return ans;
  }
};
