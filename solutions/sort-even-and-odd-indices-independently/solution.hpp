#pragma once

#include <algorithm>
#include <vector>

// Time:
// Space:

class Solution {
public:
  static std::vector<int> sortEvenOdd(const std::vector<int> &nums) {
    const int n = nums.size();

    std::vector<int> even, odd;
    for (int i = 0; i < n; ++i) {
      if (i & 1) {
        odd.push_back(nums[i]);
      } else {
        even.push_back(nums[i]);
      }
    }

    std::sort(even.begin(), even.end());
    std::sort(odd.begin(), odd.end(), std::greater<>());

    std::vector<int> ans;
    for (int i = 0; i < n; ++i) {
      ans.push_back(i & 1 ? odd[i / 2] : even[i / 2]);
    }
    return ans;
  }
};
