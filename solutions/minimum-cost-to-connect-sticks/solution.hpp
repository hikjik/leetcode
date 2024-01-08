#pragma once

#include <queue>
#include <vector>

// Time: O(NlogN)
// Space: O(N)

class Solution {
public:
  static int connectSticks(const std::vector<int> &sticks) {
    std::priority_queue<int, std::vector<int>, std::greater<>> minHeap{
        sticks.begin(), sticks.end()};
    int ans = 0;
    while (minHeap.size() > 1) {
      const auto a = minHeap.top();
      minHeap.pop();
      const auto b = minHeap.top();
      minHeap.pop();
      ans += a + b;
      minHeap.push(a + b);
    }
    return ans;
  }
};
