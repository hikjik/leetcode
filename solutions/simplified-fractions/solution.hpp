#pragma once

#include <numeric>
#include <string>
#include <vector>

// Time: O(N^2logN)
// Space: O(1)

class Solution {
public:
  static std::vector<std::string> simplifiedFractions(int n) {
    std::vector<std::string> ans;
    for (int i = 2; i <= n; ++i) {
      for (int j = 1; j < i; ++j) {
        if (std::gcd(i, j) == 1) {
          ans.push_back(std::to_string(j) + '/' + std::to_string(i));
        }
      }
    }
    return ans;
  }
};
