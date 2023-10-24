#pragma once

#include <algorithm>
#include <unordered_map>
#include <vector>

class Solution {
public:
  static std::vector<int> frequencySort(std::vector<int> nums) {
    std::unordered_map<int, int> counter;
    for (auto a : nums) {
      ++counter[a];
    }
    std::sort(nums.begin(), nums.end(), [&](int a, int b) {
      return std::make_pair(counter[a], b) < std::make_pair(counter[b], a);
    });
    return nums;
  }
};
