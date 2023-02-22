#pragma once

#include <limits>
#include <vector>

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
