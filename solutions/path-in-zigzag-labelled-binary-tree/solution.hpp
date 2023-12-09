#pragma once

#include <bit>
#include <vector>

// Time: O(N)
// Space: O(1)

class Solution {
public:
  static std::vector<int> pathInZigZagTree(unsigned label) {
    std::vector<int> ans(std::bit_width(label), label);
    for (int i = ans.size() - 2; i >= 0; --i) {
      ans[i] = 3 * (1 << i) - 1 - ans[i + 1] / 2;
    }
    return ans;
  }
};
