#pragma once

#include <ranges>
#include <vector>

// Time: O(NlogN)
// Space: O(N)

class Solution {
public:
  static int bagOfTokensScore(std::vector<int> tokens, int power) {
    std::ranges::sort(tokens);
    int ans = 0;
    for (int i = 0, j = tokens.size() - 1; i <= j;) {
      if (tokens[i] <= power) {
        power -= tokens[i++];
        ++ans;
      } else if (ans && i < j) {
        power += tokens[j--];
        --ans;
      } else {
        break;
      }
    }
    return ans;
  }
};
