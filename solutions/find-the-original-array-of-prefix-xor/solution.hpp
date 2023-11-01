#pragma once

#include <functional>
#include <numeric>
#include <vector>

/*
  2433. Find The Original Array of Prefix Xor
  https://leetcode.com/problems/find-the-original-array-of-prefix-xor/
  Difficulty: Medium
  Tags: Array, Bit Manipulation
  Time:
  Space:
*/

class Solution {
public:
  static std::vector<int> findArray(const std::vector<int> &pref) {
    std::vector<int> arr(pref.size());
    std::adjacent_difference(pref.begin(), pref.end(), arr.begin(),
                             std::bit_xor{});
    return arr;
  }
};
