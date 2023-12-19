#pragma once

#include <string>
#include <vector>

// Time: O(N^2)
// Space: O(N)

class Solution {
public:
  static int maxProduct(const std::vector<std::string> &words) {
    const int n = words.size();
    std::vector<int> masks(n);
    for (int i = 0; i < n; ++i) {
      for (auto c : words[i]) {
        masks[i] |= 1 << (c - 'a');
      }
    }

    int ans = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < i; ++j) {
        if (!(masks[i] & masks[j])) {
          const int product = words[i].size() * words[j].size();
          ans = std::max(ans, product);
        }
      }
    }
    return ans;
  }
};
