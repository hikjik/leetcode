#pragma once

#include <algorithm>
#include <numeric>
#include <vector>

/*
  1893. Check if All the Integers in a Range Are Covered
  https://leetcode.com/problems/check-if-all-the-integers-in-a-range-are-covered/
  Difficulty: Easy
  Tags: Array, Hash Table, Prefix Sum
  Time:
  Space:
*/

class Solution {
public:
  static constexpr int kMax = 50;

  static bool isCovered(const std::vector<std::vector<int>> &ranges, int left,
                        int right) {
    std::vector<int> ps(kMax + 2);
    for (const auto &range : ranges) {
      ++ps[range[0]], --ps[range[1] + 1];
    }
    std::partial_sum(ps.cbegin(), ps.cend(), ps.begin());
    return std::all_of(ps.cbegin() + left, ps.cbegin() + right + 1,
                       [](int a) { return a > 0; });
  }
};
