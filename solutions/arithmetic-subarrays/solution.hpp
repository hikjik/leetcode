#pragma once

#include <algorithm>
#include <vector>

/*
  1630. Arithmetic Subarrays
  https://leetcode.com/problems/arithmetic-subarrays/
  Difficulty: Medium
  Tags: Array, Sorting
  Time:
  Space:
*/

class Solution {
public:
  static std::vector<bool>
  checkArithmeticSubarrays(const std::vector<int> &nums,
                           const std::vector<int> &l,
                           const std::vector<int> &r) {
    std::vector<bool> is_arithmetic(l.size(), true);
    for (size_t i = 0; i < l.size(); ++i) {
      std::vector<int> sub_array(nums.begin() + l[i], nums.begin() + r[i] + 1);
      std::sort(sub_array.begin(), sub_array.end());
      const auto difference = sub_array[1] - sub_array[0];
      for (size_t j = 0; j < sub_array.size() - 1; j++) {
        if (sub_array[j + 1] - sub_array[j] != difference) {
          is_arithmetic[i] = false;
          break;
        }
      }
    }
    return is_arithmetic;
  }
};
