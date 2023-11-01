#pragma once

#include <queue>
#include <unordered_map>
#include <vector>

/*
  347. Top K Frequent Elements
  https://leetcode.com/problems/top-k-frequent-elements/
  Difficulty: Medium
  Tags: Array, Hash Table, Divide and Conquer, Sorting, Heap (Priority Queue),
        Bucket Sort, Counting, Quickselect
  Time:
  Space:
*/

class Solution {
public:
  static std::vector<int> topKFrequent(const std::vector<int> &nums, size_t k) {
    std::unordered_map<int, int> counter;
    for (auto num : nums) {
      counter[num]++;
    }

    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>,
                        std::greater<std::pair<int, int>>>
        queue;
    for (const auto &[num, frequency] : counter) {
      queue.emplace(frequency, num);
      if (queue.size() > k) {
        queue.pop();
      }
    }

    std::vector<int> top_k;
    while (!queue.empty()) {
      top_k.push_back(queue.top().second);
      queue.pop();
    }
    return top_k;
  }
};
