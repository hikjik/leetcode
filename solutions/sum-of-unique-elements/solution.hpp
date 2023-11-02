#pragma once

#include <unordered_map>
#include <vector>

// Time:
// Space:

class Solution {
public:
  static int sumOfUnique(const std::vector<int> &nums) {
    std::unordered_map<int, int> counter;
    for (auto a : nums) {
      ++counter[a];
    }
    int sum = 0;
    for (const auto &[a, f] : counter) {
      if (f == 1) {
        sum += a;
      }
    }
    return sum;
  }
};
