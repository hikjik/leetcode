#pragma once

#include <vector>

class Solution {
public:
  static std::vector<int> circularGameLosers(int n, int k) {
    std::vector<bool> seen(n);
    for (int i = 0, steps = k; !seen[i]; i = (i + steps) % n, steps += k) {
      seen[i] = true;
    }

    std::vector<int> ans;
    for (int i = 0; i < n; ++i) {
      if (!seen[i]) {
        ans.push_back(i + 1);
      }
    }
    return ans;
  }
};
