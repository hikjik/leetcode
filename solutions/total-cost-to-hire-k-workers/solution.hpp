#pragma once

#include <queue>
#include <vector>

/*
  2462. Total Cost to Hire K Workers
  https://leetcode.com/problems/total-cost-to-hire-k-workers/
  Difficulty: Medium
  Tags: Array, Two Pointers, Heap (Priority Queue), Simulation
  Time:
  Space:
*/

class Solution {
public:
  static long long totalCost(const std::vector<int> &costs, int k,
                             size_t candidates) {
    std::priority_queue<int, std::vector<int>, std::greater<>> min_heap_left;
    std::priority_queue<int, std::vector<int>, std::greater<>> min_heap_right;

    long long cost = 0;
    size_t left = 0, right = costs.size() - 1;
    while (k--) {
      while (min_heap_left.size() < candidates && left <= right) {
        min_heap_left.push(costs[left++]);
      }
      while (min_heap_right.size() < candidates && left <= right) {
        min_heap_right.push(costs[right--]);
      }

      if (min_heap_left.empty() ||
          !min_heap_right.empty() &&
              min_heap_right.top() < min_heap_left.top()) {
        cost += min_heap_right.top();
        min_heap_right.pop();
      } else {
        cost += min_heap_left.top();
        min_heap_left.pop();
      }
    }

    return cost;
  }
};
