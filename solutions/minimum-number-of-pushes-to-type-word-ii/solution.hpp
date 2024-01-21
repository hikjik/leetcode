#pragma once

#include <string>
#include <vector>

// Time: O(N+AlogA)
// Space: O(A)

class Solution {
public:
  static int minimumPushes(std::string word) {
    std::vector<int> freq(26);
    for (auto c : word) {
      ++freq[c - 'a'];
    }
    std::ranges::sort(freq, std::greater{});
    int ans = 0;
    for (int i = 0; i < std::ssize(freq); ++i) {
      ans += (i / 8 + 1) * freq[i];
    }
    return ans;
  }
};
