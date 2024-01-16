#pragma once

#include <ranges>
#include <vector>

// Time: O(NlogN)
// Space: O(N)

class Solution {
public:
  static constexpr int kCapacity = 5000;

  static int maxNumberOfApples(std::vector<int> weight) {
    std::ranges::sort(weight);
    int sum = 0;
    for (int i = 0; i < std::ssize(weight); ++i) {
      sum += weight[i];
      if (sum > kCapacity) {
        return i;
      }
    }
    return weight.size();
  }
};
