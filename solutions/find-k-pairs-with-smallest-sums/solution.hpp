#pragma once

#include <queue>
#include <vector>

// Time:
// Space:

class Solution {
private:
  struct Pair {
    size_t i, j;
    int sum;
  };

  struct PairGreater {
    bool operator()(const Pair &lhs, const Pair &rhs) {
      return lhs.sum > rhs.sum;
    }
  };

public:
  static std::vector<std::vector<int>>
  kSmallestPairs(const std::vector<int> &nums1, const std::vector<int> &nums2,
                 size_t k) {
    std::priority_queue<Pair, std::vector<Pair>, PairGreater> queue;
    for (size_t i = 0; i < std::min(k, nums1.size()); ++i) {
      queue.push({i, 0, nums1[i] + nums2[0]});
    }

    std::vector<std::vector<int>> pairs;
    while (!queue.empty() && pairs.size() < k) {
      const auto [i, j, _] = queue.top();
      queue.pop();

      pairs.push_back({nums1[i], nums2[j]});

      if (j + 1 < nums2.size()) {
        queue.push({i, j + 1, nums1[i] + nums2[j + 1]});
      }
    }
    return pairs;
  }
};
