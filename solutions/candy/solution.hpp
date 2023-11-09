#pragma once

#include <algorithm>
#include <numeric>
#include <vector>

// Time: O(N)
// Space: O(N)

class Solution {
public:
  static int candy(const std::vector<int> &ratings) {
    const int n = ratings.size();

    std::vector<int> candies(n, 1);

    for (int i = 1; i < n; ++i) {
      if (ratings[i] > ratings[i - 1]) {
        candies[i] = candies[i - 1] + 1;
      }
    }

    for (int i = n - 2; i >= 0; --i) {
      if (ratings[i] > ratings[i + 1]) {
        candies[i] = std::max(candies[i], candies[i + 1] + 1);
      }
    }

    return std::reduce(candies.begin(), candies.end());
  }
};
