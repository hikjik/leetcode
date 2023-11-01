#pragma once

#include <queue>
#include <vector>

/*
  2336. Smallest Number in Infinite Set
  https://leetcode.com/problems/smallest-number-in-infinite-set/
  Difficulty: Medium
  Tags: Hash Table, Design, Heap (Priority Queue)
  Time:
  Space:
*/

class SmallestInfiniteSet {
public:
  int popSmallest() {
    if (min_heap.empty()) {
      return minimum++;
    }

    const auto value = min_heap.top();
    while (!min_heap.empty() && min_heap.top() == value) {
      min_heap.pop();
    }
    return value;
  }

  void addBack(int num) {
    if (num < minimum) {
      min_heap.push(num);
    }
  }

private:
  int minimum = 1;
  std::priority_queue<int, std::vector<int>, std::greater<int>> min_heap;
};
