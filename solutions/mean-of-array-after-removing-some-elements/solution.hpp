#pragma once

#include <algorithm>
#include <numeric>
#include <vector>

/*
  1619. Mean of Array After Removing Some Elements
  https://leetcode.com/problems/mean-of-array-after-removing-some-elements/
  Difficulty: Easy
  Tags: Array, Sorting
  Time:
  Space:
*/

class Solution {
public:
  static double trimMean(std::vector<int> arr) {
    std::sort(arr.begin(), arr.end());
    const auto trim = arr.size() / 20;
    const auto count = arr.size() - 2 * trim;
    const auto sum = std::accumulate(arr.begin() + trim, arr.end() - trim, 0);
    return sum * 1.0 / count;
  }
};
