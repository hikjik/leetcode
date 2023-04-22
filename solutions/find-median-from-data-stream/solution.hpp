#pragma once

#include <queue>
#include <vector>

class MedianFinder {
public:
  void addNum(int num) {
    if (max_heap.empty() || num <= max_heap.top()) {
      max_heap.push(num);
      if (max_heap.size() - min_heap.size() > 1) {
        min_heap.push(max_heap.top());
        max_heap.pop();
      }
    } else {
      min_heap.push(num);
      if (max_heap.size() < min_heap.size()) {
        max_heap.push(min_heap.top());
        min_heap.pop();
      }
    }
  }

  double findMedian() {
    if (max_heap.size() == min_heap.size()) {
      return (max_heap.top() + min_heap.top()) * 0.5;
    }
    return max_heap.top();
  }

private:
  std::priority_queue<int> max_heap;
  std::priority_queue<int, std::vector<int>, std::greater<>> min_heap;
};
