#pragma once

#include <vector>

class Solution {
public:
  static std::vector<int> mostVisited(int n, const std::vector<int> &rounds) {
    std::vector<int> ans;
    if (rounds.front() <= rounds.back()) {
      for (int i = rounds.front(); i <= rounds.back(); ++i) {
        ans.push_back(i);
      }
    } else {
      for (int i = 1; i <= rounds.back(); ++i) {
        ans.push_back(i);
      }
      for (int i = rounds.front(); i <= n; ++i) {
        ans.push_back(i);
      }
    }
    return ans;
  }
};
