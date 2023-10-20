#pragma once

#include <unordered_map>
#include <vector>

class Solution {
public:
  static int mostFrequent(const std::vector<int> &nums, int key) {
    std::unordered_map<int, int> counter;
    for (int i = 0; i + 1 < std::ssize(nums); ++i) {
      if (nums[i] == key) {
        ++counter[nums[i + 1]];
      }
    }

    return std::max_element(counter.begin(), counter.end(),
                            [](const auto &lhs, const auto &rhs) {
                              return lhs.second < rhs.second;
                            })
        ->first;
  }
};
