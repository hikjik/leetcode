#pragma once

#include <algorithm>
#include <vector>

// Time: O(N)
// Space: O(1)

namespace count_bits {

// Time: O(NlogM), where M = UINT_MAX
// Space: O(1)
class Solution {
public:
  static int singleNumber(const std::vector<int> &nums) {
    int ans = 0;
    for (int i = 0; i < 32; ++i) {
      const auto cnt = std::count_if(nums.begin(), nums.end(),
                                     [i](int a) { return a >> i & 1; });
      if (cnt % 3 == 1) {
        ans |= 1 << i;
      }
    }
    return ans;
  }
};

} // namespace count_bits

namespace tricky {

// Time: O(N)
// Space: O(1)
class Solution {
public:
  static int singleNumber(const std::vector<int> &nums) {
    int one = 0;
    int two = 0;
    for (auto num : nums) {
      one ^= (num & ~two);
      two ^= (num & ~one);
    }
    return one;
  }
};

} // namespace tricky
