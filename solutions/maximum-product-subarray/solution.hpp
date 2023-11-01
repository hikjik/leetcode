#pragma once

#include <limits>
#include <vector>

/*
  152. Maximum Product Subarray
  https://leetcode.com/problems/maximum-product-subarray/
  Difficulty: Medium
  Tags: Array, Dynamic Programming
  Time:
  Space:
*/

class Solution {
public:
  static int maxProduct(const std::vector<int> &nums) {
    int max_product = std::numeric_limits<int>::min();
    int max = 1, min = 1;
    for (auto num : nums) {
      if (num < 0) {
        std::swap(max, min);
      }
      max = std::max(num, num * max);
      min = std::min(num, num * min);
      max_product = std::max(max_product, max);
    }
    return max_product;
  }
};
