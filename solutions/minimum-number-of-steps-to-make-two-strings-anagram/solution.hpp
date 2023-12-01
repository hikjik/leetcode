#pragma once

#include <numeric>
#include <string>
#include <vector>

// Time: O(N)
// Space: O(A)

class Solution {
public:
  static int minSteps(std::string s, std::string t) {
    std::vector<int> counter(26);
    for (int i = 0; i < std::ssize(s); ++i) {
      ++counter[s[i] - 'a'], --counter[t[i] - 'a'];
    }
    return std::accumulate(counter.begin(), counter.end(), 0,
                           [](int a, int b) { return a + std::max(0, b); });
  }
};
