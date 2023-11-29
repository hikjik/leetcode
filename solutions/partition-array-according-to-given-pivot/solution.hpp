#pragma once

#include <algorithm>
#include <vector>

// Time: O(N)
// Space: O(N)

namespace stl {

using namespace std::placeholders;

// Time: O(N)
// Space: O(N)
class Solution {
public:
  static std::vector<int> pivotArray(std::vector<int> nums, int pivot) {
    std::stable_partition(nums.begin(), nums.end(),
                          std::bind(std::less{}, _1, pivot));
    std::stable_partition(nums.begin(), nums.end(),
                          std::bind(std::less_equal{}, _1, pivot));
    return nums;
  }
};

} // namespace stl

namespace pointers {

// Time: O(N)
// Space: O(N)
class Solution {
public:
  static std::vector<int> pivotArray(std::vector<int> nums, int pivot) {
    int less = 0, equal = 0, greater = 0;
    for (auto a : nums) {
      equal += a < pivot;
      greater += a <= pivot;
    }

    std::vector<int> ans(nums.size());
    for (auto a : nums) {
      if (a < pivot) {
        ans[less++] = a;
      } else if (a == pivot) {
        ans[equal++] = a;
      } else {
        ans[greater++] = a;
      }
    }
    return ans;
  }
};

} // namespace pointers
