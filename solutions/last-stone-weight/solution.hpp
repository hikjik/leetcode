#pragma once

#include <queue>
#include <vector>

/*
  1046. Last Stone Weight
  https://leetcode.com/problems/last-stone-weight/
  Difficulty: Easy
  Tags: Array, Heap (Priority Queue)
  Time:
  Space:
*/

class Solution {
public:
  static int lastStoneWeight(const std::vector<int> &stones) {
    std::priority_queue<int> queue{stones.begin(), stones.end()};
    while (queue.size() > 1) {
      const auto x = queue.top();
      queue.pop();
      const auto y = queue.top();
      queue.pop();

      if (x != y) {
        queue.push(std::abs(x - y));
      }
    }
    return queue.empty() ? 0 : queue.top();
  }
};
