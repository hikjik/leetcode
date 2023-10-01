#pragma once

#include <algorithm>
#include <vector>

class Solution {
public:
  static std::vector<int> getConcatenation(const std::vector<int> &nums) {
    const auto n = nums.size();

    std::vector<int> res(2 * n);
    for (size_t i = 0; i < n; ++i) {
      res[i] = res[i + n] = nums[i];
    }

    return res;
  }
};
