#pragma once

#include <vector>

/*
  977. Squares of a Sorted Array
  https://leetcode.com/problems/squares-of-a-sorted-array/
  Difficulty: Easy
  Tags: Array, Two Pointers, Sorting
  Time:
  Space:
*/

class Solution {
public:
  static std::vector<int> sortedSquares(const std::vector<int> &nums) {
    std::vector<int> negative;
    std::vector<int> positive;
    for (auto num : nums) {
      if (num < 0) {
        negative.push_back(num * num);
      } else {
        positive.push_back(num * num);
      }
    }

    std::vector<int> result;
    result.reserve(nums.size());
    std::merge(positive.begin(), positive.end(), negative.rbegin(),
               negative.rend(), std::back_inserter(result));
    return result;
  }
};
