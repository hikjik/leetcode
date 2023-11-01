#pragma once

#include <array>
#include <vector>

/*
  2369. Check if There is a Valid Partition For The Array
  https://leetcode.com/problems/check-if-there-is-a-valid-partition-for-the-array/
  Difficulty: Medium
  Tags: Array, Dynamic Programming
  Time:
  Space:
*/

class Solution {
public:
  static bool validPartition(const std::vector<int> &nums) {
    const int n = nums.size();
    switch (n) {
    case 1:
      return false;
    case 2:
      return valid2(0, nums);
    case 3:
      return valid3(0, nums);
    }

    std::array<bool, 3> dp;
    dp[0] = false;
    dp[1] = valid2(n - 2, nums);
    dp[2] = valid3(n - 3, nums);

    for (int i = n - 4; i >= 0; --i) {
      const auto d = valid2(i, nums) & dp[1] | valid3(i, nums) & dp[0];
      dp[0] = dp[1], dp[1] = dp[2], dp[2] = d;
    }

    return dp[2];
  }

private:
  static bool valid2(int i, const std::vector<int> &nums) {
    return nums[i] == nums[i + 1];
  }

  static bool valid3(int i, const std::vector<int> &nums) {
    return nums[i] == nums[i + 1] && nums[i] == nums[i + 2] ||
           nums[i] == nums[i + 1] - 1 && nums[i] == nums[i + 2] - 2;
  }
};
