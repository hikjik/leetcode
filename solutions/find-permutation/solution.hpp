#pragma once

#include <algorithm>
#include <numeric>
#include <string>
#include <vector>

// Time: O(N)
// Space: O(1)

class Solution {
public:
  static std::vector<int> findPermutation(std::string s) {
    std::vector<int> ans(s.size() + 1);
    for (int k = 0, i = 0; i <= std::ssize(s); ++i) {
      if (i == std::ssize(s) || s[i] == 'I') {
        for (int j = i + 1; k <= i; --j) {
          ans[k++] = j;
        }
      }
    }
    return ans;
  }
};
