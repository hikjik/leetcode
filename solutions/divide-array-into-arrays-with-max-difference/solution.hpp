#pragma once

#include <ranges>
#include <vector>

// Time: O(NlogN)
// Space: O(N)

class Solution {
public:
  static std::vector<std::vector<int>> divideArray(std::vector<int> nums,
                                                   int k) {
    std::ranges::sort(nums);
    std::vector<std::vector<int>> ans;
    for (int i = 0; i + 2 < std::ssize(nums); i += 3) {
      if (nums[i + 2] - nums[i] > k) {
        return {};
      }
      ans.push_back({nums[i], nums[i + 1], nums[i + 2]});
    }
    return ans;
  }
};
