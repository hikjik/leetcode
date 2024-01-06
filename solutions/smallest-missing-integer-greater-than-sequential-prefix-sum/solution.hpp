#pragma once

#include <unordered_set>
#include <vector>

// Time: O(N)
// Space: O(N)

class Solution {
public:
  static int missingInteger(const std::vector<int> &nums) {
    int ans = nums[0];
    for (int i = 1; i < std::ssize(nums); ++i) {
      if (nums[i] == nums[i - 1] + 1) {
        ans += nums[i];
      } else {
        break;
      }
    }

    std::unordered_set<int> set{nums.begin(), nums.end()};
    while (set.contains(ans)) {
      ++ans;
    }
    return ans;
  }
};
