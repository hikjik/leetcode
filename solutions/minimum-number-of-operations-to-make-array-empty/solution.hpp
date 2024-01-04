#pragma once

#include <unordered_map>
#include <vector>

// Time: O(N)
// Space: O(N)

class Solution {
public:
  static int minOperations(const std::vector<int> &nums) {
    std::unordered_map<int, int> cnt;
    for (auto num : nums) {
      ++cnt[num];
    }

    int ans = 0;
    for (const auto &[_, f] : cnt) {
      if (f == 1) {
        return -1;
      } else if (f % 3 == 1) {
        ans += (f - 4) / 3 + 2;
      } else {
        ans += f / 3 + (f % 3) / 2;
      }
    }
    return ans;
  }
};
