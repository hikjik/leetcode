#pragma once

#include <algorithm>
#include <queue>
#include <vector>

class Solution {
public:
  static long long maxScore(const std::vector<int> &nums1,
                            const std::vector<int> &nums2, size_t k) {
    std::vector<std::pair<int, int>> pairs;
    for (size_t i = 0; i < nums1.size(); ++i) {
      pairs.push_back({nums2[i], nums1[i]});
    }
    std::sort(pairs.begin(), pairs.end(), std::greater<>());

    long long max_score = 0;
    long long sum = 0;
    std::priority_queue<int, std::vector<int>, std::greater<int>> min_heap;
    for (const auto &[minimum, num] : pairs) {
      sum += num;
      min_heap.push(num);
      if (min_heap.size() > k) {
        sum -= min_heap.top();
        min_heap.pop();
      }
      if (min_heap.size() == k) {
        max_score = std::max(max_score, sum * minimum);
      }
    }
    return max_score;
  }
};
