#pragma once

#include <algorithm>
#include <vector>

/*
  1300. Sum of Mutated Array Closest to Target
  https://leetcode.com/problems/sum-of-mutated-array-closest-to-target/
  Difficulty: Medium
  Tags: Array, Binary Search, Sorting
  Time:
  Space:
*/

class Solution {
public:
  static int findBestValue(std::vector<int> arr, int target) {
    int left = 0, right = target;

    while (left < right) {
      const auto middle = left + (right - left) / 2;

      int sum1 = 0, sum2 = 0;
      for (auto a : arr) {
        sum1 += std::min(middle, a);
        sum2 += std::min(middle + 1, a);
      }

      if (abs(target - sum1) <= abs(target - sum2)) {
        right = middle;
      } else {
        left = middle + 1;
      }
    }

    return left;
  }
};
