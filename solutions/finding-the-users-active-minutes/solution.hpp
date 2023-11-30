#pragma once

#include <unordered_map>
#include <unordered_set>
#include <vector>

// Time: O(N)
// Space: O(N)

class Solution {
public:
  static std::vector<int>
  findingUsersActiveMinutes(const std::vector<std::vector<int>> &logs, int k) {
    std::unordered_map<int, std::unordered_set<int>> usersActiveMinutes;
    for (const auto &log : logs) {
      const auto id = log[0], time = log[1];
      usersActiveMinutes[id].insert(time);
    }

    std::vector<int> ans(k);
    for (const auto &[_, times] : usersActiveMinutes) {
      ++ans[times.size() - 1];
    }
    return ans;
  }
};
