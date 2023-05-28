#pragma once

#include <algorithm>
#include <limits>
#include <vector>

class Solution {
public:
  int minCost(int n, const std::vector<int> &cuts) {
    cuts_ = cuts;
    cuts_.push_back(0), cuts_.push_back(n);
    std::sort(cuts_.begin(), cuts_.end());

    const int m = cuts_.size();
    memo_.resize(m, std::vector<int>(m, -1));
    return minCost(0, m - 1);
  }

private:
  std::vector<std::vector<int>> memo_;
  std::vector<int> cuts_;

  int minCost(int i, int j) {
    if (i + 1 == j) {
      return 0;
    }

    auto &cost = memo_[i][j];
    if (cost != -1) {
      return cost;
    }

    cost = std::numeric_limits<int>::max();
    for (int k = i + 1; k < j; ++k) {
      cost =
          std::min(cost, minCost(i, k) + minCost(k, j) + cuts_[j] - cuts_[i]);
    }
    return cost;
  }
};
