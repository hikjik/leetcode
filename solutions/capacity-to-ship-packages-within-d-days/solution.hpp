#pragma once

#include <vector>

class Solution {
public:
  static int shipWithinDays(const std::vector<int> &weights, int days) {
    int left = *std::max_element(weights.begin(), weights.end());
    int right = std::accumulate(weights.begin(), weights.end(), 0);
    while (left < right) {
      int middle = left + (right - left) / 2;
      if (computeDays(weights, middle) > days) {
        left = middle + 1;
      } else {
        right = middle;
      }
    }
    return left;
  }

private:
  static int computeDays(const std::vector<int> &weights, int capacity) {
    int days = 1;
    int cur_sum = 0;
    for (auto w : weights) {
      if (cur_sum + w > capacity) {
        cur_sum = 0;
        days++;
      }
      cur_sum += w;
    }
    return days;
  }
};
