#pragma once

#include <queue>
#include <vector>

/*
  703. Kth Largest Element in a Stream
  https://leetcode.com/problems/kth-largest-element-in-a-stream/
  Difficulty: Easy
  Tags: Tree, Design, Binary Search Tree, Heap (Priority Queue), Binary Tree,
        Data Stream
  Time:
  Space:
*/

class KthLargest {
public:
  KthLargest(int k, const std::vector<int> &nums) : k_(k) {
    for (auto a : nums) {
      push(a);
    }
  }

  int add(int a) {
    push(a);
    return min_heap_.top();
  }

private:
  void push(int a) {
    min_heap_.push(a);
    if (min_heap_.size() > k_) {
      min_heap_.pop();
    }
  }

  std::priority_queue<int, std::vector<int>, std::greater<>> min_heap_;
  const size_t k_;
};
