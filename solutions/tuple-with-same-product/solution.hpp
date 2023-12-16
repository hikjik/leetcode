#pragma once

#include <numeric>
#include <unordered_map>
#include <vector>

// Time: O(N^2)
// Space: O(N^2)

class Solution {
public:
  static int tupleSameProduct(const std::vector<int> &nums) {
    std::unordered_map<int, int> counter;
    int ans = 0;
    for (int i = 0; i < std::ssize(nums); ++i) {
      for (int j = 0; j < i; ++j) {
        ans += 8 * counter[nums[i] * nums[j]]++;
      }
    }
    return ans;
  }
};
