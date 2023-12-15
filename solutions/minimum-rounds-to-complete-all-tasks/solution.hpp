#pragma once

#include <unordered_map>
#include <vector>

// Time: O(N)
// Space: O(N)

class Solution {
public:
  static int minimumRounds(const std::vector<int> &tasks) {
    std::unordered_map<int, int> cnt;
    for (auto task : tasks) {
      ++cnt[task];
    }

    int ans = 0;
    for (const auto [_, freq] : cnt) {
      if (freq == 1) {
        return -1;
      }
      ans += (freq + 2) / 3;
    }
    return ans;
  }
};
