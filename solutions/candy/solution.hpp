#pragma once

#include <algorithm>
#include <vector>

class Solution {
public:
  static int candy(const std::vector<int> &ratings) {
    const int n = ratings.size();

    std::vector<int> left(n, 1);
    for (int i = 1; i < n; ++i) {
      if (ratings[i] > ratings[i - 1]) {
        left[i] = left[i - 1] + 1;
      }
    }

    std::vector<int> right(n, 1);
    for (int i = n - 2; i >= 0; --i) {
      if (ratings[i] > ratings[i + 1]) {
        right[i] = right[i + 1] + 1;
      }
    }

    int sum = 0;
    for (int i = 0; i < n; ++i) {
      sum += std::max(left[i], right[i]);
    }
    return sum;
  }
};
