#pragma once

#include <algorithm>
#include <vector>

// Time:
// Space:

class Solution {
public:
  static std::vector<int> arrayRankTransform(const std::vector<int> &arr) {
    auto nums(arr);
    std::sort(nums.begin(), nums.end());
    nums.erase(std::unique(nums.begin(), nums.end()), nums.end());

    std::vector<int> rank;
    for (auto a : arr) {
      const auto lb = std::lower_bound(nums.begin(), nums.end(), a);
      rank.push_back(std::distance(nums.begin(), lb) + 1);
    }
    return rank;
  }
};
