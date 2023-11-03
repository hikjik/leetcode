#pragma once

#include <unordered_map>
#include <vector>

// Time:
// Space:

class Solution {
public:
  static int mostFrequentEven(const std::vector<int> &nums) {
    std::unordered_map<int, int> counter;
    int most_frequent = -1;
    for (auto num : nums) {
      if (num & 1) {
        continue;
      }
      ++counter[num];
      if (counter[num] > counter[most_frequent] ||
          counter[num] == counter[most_frequent] && num < most_frequent) {
        most_frequent = num;
      }
    }
    return most_frequent;
  }
};
