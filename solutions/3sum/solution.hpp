#pragma once

#include <algorithm>
#include <vector>

class Solution {
public:
  static std::vector<std::vector<int>> threeSum(std::vector<int> nums) {
    int n = nums.size();
    std::vector<std::vector<int>> triplets;

    std::sort(nums.begin(), nums.end());

    for (int i = 0; i < n; ++i) {
      if (i > 0 && nums[i - 1] == nums[i]) {
        continue;
      }

      int l = i + 1, r = n - 1;
      while (l < r) {
        int sum = nums[l] + nums[r] + nums[i];

        if (sum == 0) {
          triplets.push_back({nums[i], nums[l], nums[r]});
          while (l < r && nums[l] == nums[l + 1]) {
            ++l;
          }
          while (l < r && nums[r - 1] == nums[r]) {
            --r;
          }
        }

        if (sum < 0) {
          l++;
        } else {
          r--;
        }
      }
    }
    return triplets;
  }
};
