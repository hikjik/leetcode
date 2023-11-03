#pragma once

#include <string>
#include <vector>

// Time: O(N)
// Space: O(1)

class Solution {
public:
  static std::vector<std::string> buildArray(const std::vector<int> &target,
                                             int n) {
    std::vector<std::string> ops;
    for (int i = 1, j = 0; i <= n && j < std::ssize(target); ++i) {
      ops.push_back("Push");
      if (target[j] != i) {
        ops.push_back("Pop");
      } else {
        ++j;
      }
    }
    return ops;
  }
};
