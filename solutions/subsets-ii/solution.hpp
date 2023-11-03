#pragma once

#include <algorithm>
#include <vector>

// Time:
// Space:

class Solution {
public:
  static std::vector<std::vector<int>> subsetsWithDup(std::vector<int> nums) {
    std::sort(nums.begin(), nums.end());

    std::vector<std::vector<int>> subsets;
    std::vector<int> subset;
    enumerateSubsets(0, nums, &subset, &subsets);
    return subsets;
  }

private:
  static void enumerateSubsets(size_t i, const std::vector<int> &nums,
                               std::vector<int> *subset,
                               std::vector<std::vector<int>> *subsets) {
    subsets->push_back(*subset);

    for (size_t j = i; j < nums.size(); ++j) {
      if (j > i && nums[j - 1] == nums[j]) {
        continue;
      }
      subset->push_back(nums[j]);
      enumerateSubsets(j + 1, nums, subset, subsets);
      subset->pop_back();
    }
  }
};
