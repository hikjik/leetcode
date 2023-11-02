#pragma once

#include <vector>

// Time:
// Space:

class Solution {
public:
  static std::vector<std::vector<int>> subsets(const std::vector<int> &nums) {
    std::vector<std::vector<int>> subsets;
    std::vector<int> subset;
    enumerateSubsets(0, nums, &subset, &subsets);
    return subsets;
  }

private:
  static void enumerateSubsets(size_t i, const std::vector<int> &nums,
                               std::vector<int> *subset,
                               std::vector<std::vector<int>> *subsets) {
    if (i == nums.size()) {
      subsets->push_back(*subset);
      return;
    }

    enumerateSubsets(i + 1, nums, subset, subsets);
    subset->push_back(nums[i]);
    enumerateSubsets(i + 1, nums, subset, subsets);
    subset->pop_back();
  }
};
