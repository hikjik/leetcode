#pragma once

#include <vector>

class Solution {
public:
  static std::vector<std::vector<int>> fourSum(std::vector<int> nums,
                                               int target) {
    std::sort(nums.begin(), nums.end());
    return kSum(4, 0, target, nums);
  }

private:
  static std::vector<std::vector<int>>
  kSum(int k, size_t start, long long target, const std::vector<int> &nums) {
    if (start == nums.size()) {
      return {};
    }
    if (nums[start] > target / k || nums.back() < target / k) {
      return {};
    }

    if (k == 2) {
      return twoSum(start, target, nums);
    }

    std::vector<std::vector<int>> res;
    for (size_t i = start; i + k <= nums.size(); ++i) {
      if (i == start || nums[i] != nums[i - 1]) {
        for (const auto &r : kSum(k - 1, i + 1, target - nums[i], nums)) {
          res.push_back({nums[i]});
          res.back().insert(res.back().end(), r.begin(), r.end());
        }
      }
    }
    return res;
  }

  static std::vector<std::vector<int>> twoSum(size_t start, long long target,
                                              const std::vector<int> &nums) {
    std::vector<std::vector<int>> res;
    auto left = start, right = nums.size() - 1;
    while (left < right) {
      const auto sum = nums[left] + nums[right];
      if (sum < target || left > start && nums[left] == nums[left - 1]) {
        ++left;
      } else if (sum > target ||
                 right + 1 < nums.size() && nums[right] == nums[right + 1]) {
        --right;
      } else {
        res.push_back({nums[left++], nums[right--]});
      }
    }
    return res;
  }
};
