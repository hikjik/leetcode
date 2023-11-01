#pragma once

#include <algorithm>
#include <vector>

/*
  1751. Maximum Number of Events That Can Be Attended II
  https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended-ii/
  Difficulty: Hard
  Tags: Array, Binary Search, Dynamic Programming, Sorting
  Time:
  Space:
*/

class Solution {
public:
  static int maxValue(std::vector<std::vector<int>> events, int k) {
    std::vector dp(events.size(), std::vector<int>(k + 1, -1));
    std::sort(events.begin(), events.end());
    return maxValue(events, 0, k, &dp);
  }

private:
  static int maxValue(const std::vector<std::vector<int>> &events, size_t i,
                      int k, std::vector<std::vector<int>> *dp) {
    if (k == 0 || i == events.size()) {
      return 0;
    }

    auto &value = (*dp)[i][k];
    if (value != -1) {
      return value;
    }

    const auto ub =
        std::upper_bound(events.begin() + i, events.end(), events[i][1],
                         [](int end, const auto &a) { return a[0] > end; });
    const auto distance = std::distance(events.begin(), ub);
    value = std::max(events[i][2] + maxValue(events, distance, k - 1, dp),
                     maxValue(events, i + 1, k, dp));
    return value;
  }
};
