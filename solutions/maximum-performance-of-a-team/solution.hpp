#pragma once

#include <algorithm>
#include <queue>
#include <vector>

// Time:
// Space:

class Solution {
private:
  static const int kMod = 1e9 + 7;

public:
  static int maxPerformance(int n, const std::vector<int> &speed,
                            const std::vector<int> &efficiency, size_t k) {
    std::vector<std::pair<int, int>> pairs;
    for (int i = 0; i < n; ++i) {
      pairs.push_back({efficiency[i], speed[i]});
    }
    std::sort(pairs.begin(), pairs.end(), std::greater<>());

    long long max_performance = 0;
    long long sum = 0;
    std::priority_queue<int, std::vector<int>, std::greater<int>> min_heap;
    for (const auto &[minimum, num] : pairs) {
      sum += num;
      min_heap.push(num);
      if (min_heap.size() > k) {
        sum -= min_heap.top();
        min_heap.pop();
      }
      max_performance = std::max(max_performance, sum * minimum);
    }
    return max_performance % kMod;
  }
};
