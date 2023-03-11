#pragma once

#include <vector>

class Solution {
public:
  static int minDays(const std::vector<int> &bloom_days, int m, int k) {
    if (1UL * m * k > bloom_days.size()) {
      return -1;
    }

    int left = 1, right = 1e9;
    while (left < right) {
      const auto middle = left + (right - left) / 2;

      int bouquets = 0, cnt = 0;
      for (auto day : bloom_days) {
        day > middle ? cnt = 0 : cnt++;
        if (cnt == k) {
          bouquets++;
          cnt = 0;
        }
      }

      bouquets < m ? left = middle + 1 : right = middle;
    }
    return left;
  }
};
