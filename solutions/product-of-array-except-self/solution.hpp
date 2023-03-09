#pragma once

#include <vector>

class Solution {
public:
  static std::vector<int> productExceptSelf(const std::vector<int> &nums) {
    int n = nums.size();
    std::vector<int> products(n, 1);
    for (int i = 1; i < n; ++i) {
      products[i] = products[i - 1] * nums[i - 1];
    }

    int suffix = 1;
    for (int i = n - 1; i >= 0; --i) {
      products[i] *= suffix;
      suffix *= nums[i];
    }
    return products;
  }
};
