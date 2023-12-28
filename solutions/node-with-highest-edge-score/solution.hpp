#pragma once

#include <algorithm>
#include <vector>

// Time: O(N)
// Space: O(N)

class Solution {
public:
  static int edgeScore(const std::vector<int> &edges) {
    std::vector<long long> scores(edges.size());
    for (int i = 0; i < std::ssize(edges); ++i) {
      scores[edges[i]] += i;
    }
    return std::ranges::max_element(scores) - scores.cbegin();
  }
};
