#pragma once

#include <string>

// Time: O(N)
// Space: O(N)

class Solution {
public:
  static std::string getSmallestString(int n, int k) {
    std::string ans(n, 'a');
    for (k -= n; k; k -= std::min(k, 25)) {
      ans[--n] += std::min(k, 25);
    }
    return ans;
  }
};
