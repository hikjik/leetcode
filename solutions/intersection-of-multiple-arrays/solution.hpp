#pragma once

#include <vector>

class Solution {
public:
  static constexpr int kMaxValue = 1000;

  static std::vector<int>
  intersection(const std::vector<std::vector<int>> &nums) {
    std::vector<size_t> counter(kMaxValue + 1);
    for (const auto &arr : nums) {
      for (auto a : arr) {
        ++counter[a];
      }
    }

    std::vector<int> intersection;
    for (size_t i = 1; i < counter.size(); ++i) {
      if (counter[i] == nums.size()) {
        intersection.push_back(i);
      }
    }
    return intersection;
  }
};
