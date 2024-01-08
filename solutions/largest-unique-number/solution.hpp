#pragma once

#include <unordered_map>
#include <vector>

// Time: O(N)
// Space: O(N)

class Solution {
public:
  static int largestUniqueNumber(const std::vector<int> &nums) {
    std::unordered_map<int, int> cnt;
    for (auto num : nums) {
      ++cnt[num];
    }

    int ans = -1;
    for (auto num : nums) {
      if (cnt[num] == 1) {
        ans = std::max(ans, num);
      }
    }
    return ans;
  }
};
