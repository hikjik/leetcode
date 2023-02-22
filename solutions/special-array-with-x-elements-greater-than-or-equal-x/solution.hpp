#pragma once

#include <vector>

class Solution {
  static const int MAX_VALUE = 1000;

public:
  static int specialArray(const std::vector<int> &nums) {
    int counter[MAX_VALUE + 1] = {};

    for (auto num : nums) {
      counter[num]++;
    }

    int total = nums.size();
    for (int i = 0; i < MAX_VALUE + 1; ++i) {
      if (total == i) {
        return i;
      }
      total -= counter[i];
    }
    return -1;
  }
};
