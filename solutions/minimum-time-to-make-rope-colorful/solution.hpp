#pragma once

#include <string>
#include <vector>

// Time: O(N)
// Space: O(1)

class Solution {
public:
  static int minCost(std::string colors, const std::vector<int> &neededTime) {
    int ans = 0;
    for (int l = 0, r = 1; r < std::ssize(colors); ++r) {
      if (colors[l] == colors[r]) {
        ans += std::min(neededTime[l], neededTime[r]);
      }
      if (colors[l] != colors[r] || neededTime[r] > neededTime[l]) {
        l = r;
      }
    }
    return ans;
  }
};
