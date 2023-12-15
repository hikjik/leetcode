#pragma once

#include <string>
#include <vector>

// Time: O(N)
// Space: O(1)

class Solution {
public:
  static std::vector<int> divisibilityArray(std::string word, int m) {
    std::vector<int> ans;
    for (long long num = 0; auto c : word) {
      num = (num * 10 + c - '0') % m;
      ans.push_back(num ? 0 : 1);
    }
    return ans;
  }
};
