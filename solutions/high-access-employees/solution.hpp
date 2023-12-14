#pragma once

#include <string>
#include <vector>

// Time: O(NlogN)
// Space: O(N)

class Solution {
public:
  static std::vector<std::string>
  findHighAccessEmployees(std::vector<std::vector<std::string>> access_times) {
    std::ranges::sort(access_times);
    std::vector<std::string> ans;
    for (int i = 0; i + 2 < std::ssize(access_times); ++i) {
      if (!ans.empty() && ans.back() == access_times[i][0]) {
        continue;
      }
      if (access_times[i][0] != access_times[i + 2][0]) {
        continue;
      }
      if (std::stoi(access_times[i + 2][1]) - std::stoi(access_times[i][1]) <
          100) {
        ans.push_back(access_times[i][0]);
      }
    }
    return ans;
  }
};
