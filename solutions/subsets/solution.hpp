#pragma once

#include <span>
#include <vector>

// Time: O(N2^N)
// Space: O(N)

class Solution {
public:
  static std::vector<std::vector<int>> subsets(const std::vector<int> &nums) {
    std::vector<int> subset;
    std::vector<std::vector<int>> subsets;
    enumerateSubsets(std::span{nums}, &subset, &subsets);
    return subsets;
  }

private:
  static void enumerateSubsets(std::span<const int> nums,
                               std::vector<int> *subset,
                               std::vector<std::vector<int>> *subsets) {
    if (nums.empty()) {
      subsets->push_back(*subset);
      return;
    }
    enumerateSubsets(nums.subspan(1), subset, subsets);
    subset->push_back(nums[0]);
    enumerateSubsets(nums.subspan(1), subset, subsets);
    subset->pop_back();
  }
};
