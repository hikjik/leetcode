#pragma once

#include <cmath>
#include <vector>

// K - max distance
// Time: O(NM+K)
// Space: O(NM+K)

class Solution {
public:
  static constexpr int kMaxDist = 2000;

  static std::vector<int>
  assignBikes(const std::vector<std::vector<int>> &workers,
              const std::vector<std::vector<int>> &bikes) {
    const int n = workers.size(), m = bikes.size();
    std::vector<std::vector<std::pair<int, int>>> buckets(kMaxDist);
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        buckets[distance(workers[i], bikes[j])].push_back({i, j});
      }
    }

    std::vector<bool> bikeUsed(m);
    std::vector<int> ans(n, -1);
    for (const auto &bucket : buckets) {
      for (const auto &[worker, bike] : bucket) {
        if (ans[worker] == -1 && !bikeUsed[bike]) {
          bikeUsed[bike] = true;
          ans[worker] = bike;
        }
      }
    }
    return ans;
  }

private:
  static int distance(const std::vector<int> &p1, const std::vector<int> &p2) {
    return std::abs(p1[0] - p2[0]) + std::abs(p1[1] - p2[1]);
  }
};
