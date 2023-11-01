#pragma once

#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <vector>

/*
  1. Two Sum
  https://leetcode.com/problems/two-sum/
  Difficulty: Easy
  Tags: Array, Hash Table
  Time: O(N)
  Space: O(N)
*/

namespace hash_table {

// Time: O(N)
// Space: O(N)

class Solution {
public:
  static std::vector<int> twoSum(const std::vector<int> &nums, int target) {
    std::unordered_map<int, int> indexes;
    for (int i = 0; i < std::ssize(nums); ++i) {
      if (indexes.contains(nums[i])) {
        return {indexes[nums[i]], i};
      }
      indexes[target - nums[i]] = i;
    }
    return {};
  }
};

} // namespace hash_table

namespace two_pointers {

// Time: O(NlogN)
// Space: O(N)

class Solution {
public:
  static std::vector<int> twoSum(const std::vector<int> &nums, int target) {
    std::vector<int> indexes(nums.size());
    std::iota(indexes.begin(), indexes.end(), 0);
    std::sort(indexes.begin(), indexes.end(),
              [&nums](int i, int j) { return nums[i] < nums[j]; });
    for (int l = 0, r = indexes.size() - 1; l < r;) {
      const auto sum = nums[indexes[l]] + nums[indexes[r]];
      if (sum == target) {
        return {indexes[l], indexes[r]};
      }
      sum < target ? ++l : --r;
    }
    return {};
  }
};

} // namespace two_pointers

namespace brute_force {

// Time: O(N^2)
// Space: O(1)

class Solution {
public:
  static std::vector<int> twoSum(const std::vector<int> &nums, int target) {
    for (int i = 0; i < std::ssize(nums); ++i) {
      for (int j = i + 1; j < std::ssize(nums); ++j) {
        if (nums[i] + nums[j] == target) {
          return {i, j};
        }
      }
    }
    return {};
  }
};

} // namespace brute_force
