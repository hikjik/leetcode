#pragma once

#include <unordered_map>
#include <vector>

// Time: O(N)
// Space: O(N)

class Solution {
public:
  static int findMaxLength(const std::vector<int> &nums) {
    int ans = 0;
    std::unordered_map<int, int> map{{0, -1}};
    int sum = 0;
    for (int i = 0; i < std::ssize(nums); ++i) {
      sum += nums[i] ? 1 : -1;
      if (map.contains(sum)) {
        ans = std::max(ans, i - map[sum]);
      } else {
        map[sum] = i;
      }
    }
    return ans;
  }
};
