#pragma once

#include <unordered_map>
#include <vector>

/*
  560. Subarray Sum Equals K
  https://leetcode.com/problems/subarray-sum-equals-k/
  Difficulty: Medium
  Tags: Array, Hash Table, Prefix Sum
  Time:
  Space:
*/

class Solution {
public:
  static int subarraySum(const std::vector<int> &nums, int k) {
    int cnt = 0;
    int prefix_sum = 0;
    std::unordered_map<int, int> map{{prefix_sum, 1}};
    for (auto num : nums) {
      prefix_sum += num;
      if (auto it = map.find(prefix_sum - k); it != map.end()) {
        cnt += it->second;
      }
      map[prefix_sum]++;
    }
    return cnt;
  }
};
