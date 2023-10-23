#pragma once

#include <algorithm>
#include <unordered_map>
#include <vector>

class Solution {
public:
  static bool divideArray(const std::vector<int> &nums) {
    std::unordered_map<int, int> counter;
    for (auto a : nums) {
      ++counter[a];
    }
    return std::all_of(counter.begin(), counter.end(),
                       [](const auto &p) { return p.second % 2 == 0; });
  }
};
