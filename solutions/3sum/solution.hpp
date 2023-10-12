#pragma once

#include <algorithm>
#include <vector>

class Solution {
public:
  static std::vector<std::vector<int>> threeSum(std::vector<int> nums) {
    const int n = nums.size();

    std::sort(nums.begin(), nums.end());

    std::vector<std::vector<int>> triplets;
    for (int i = 0; i < n; ++i) {
      if (i > 0 && nums[i - 1] == nums[i]) {
        continue;
      }

      int l = i + 1, r = n - 1;
      while (l < r) {
        const auto sum = nums[l] + nums[r] + nums[i];
        if (sum == 0) {
          triplets.push_back({nums[i], nums[l], nums[r]});
          while (l < r && nums[l] == nums[l + 1]) {
            ++l;
          }
          while (l < r && nums[r - 1] == nums[r]) {
            --r;
          }
        }
        sum < 0 ? ++l : --r;
      }
    }
    return triplets;
  }
};
