#pragma once

#include <queue>
#include <vector>

// Time: O(NlogN)
// Space: O(N)

class Solution {
public:
  static int furthestBuilding(const std::vector<int> &heights, int bricks,
                              int ladders) {
    std::priority_queue<int, std::vector<int>, std::greater<>> minHeap;
    for (int i = 1; i < std::ssize(heights); ++i) {
      const auto diff = heights[i] - heights[i - 1];
      if (diff <= 0) {
        continue;
      }

      minHeap.push(diff);
      if (std::ssize(minHeap) > ladders) {
        bricks -= minHeap.top();
        minHeap.pop();
      }

      if (bricks < 0) {
        return i - 1;
      }
    }
    return heights.size() - 1;
  }
};
