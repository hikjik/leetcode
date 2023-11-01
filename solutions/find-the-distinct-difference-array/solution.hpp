#pragma once

#include <unordered_map>
#include <vector>

/*
  2670. Find the Distinct Difference Array
  https://leetcode.com/problems/find-the-distinct-difference-array/
  Difficulty: Easy
  Tags: Array, Hash Table
  Time:
  Space:
*/

class Solution {
public:
  static std::vector<int>
  distinctDifferenceArray(const std::vector<int> &nums) {
    std::unordered_map<int, int> left, right;
    for (auto num : nums) {
      ++right[num];
    }

    std::vector<int> ans;
    int l = 0, r = right.size();
    for (auto num : nums) {
      if (!left[num]++) {
        ++l;
      }
      if (!--right[num]) {
        --r;
      }
      ans.push_back(l - r);
    }
    return ans;
  }
};
