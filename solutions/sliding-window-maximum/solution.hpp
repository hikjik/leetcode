#pragma once

#include <queue>
#include <vector>

template <typename ValueType, typename Comparator = std::less<>>
/*
  239. Sliding Window Maximum
  https://leetcode.com/problems/sliding-window-maximum/
  Difficulty: Hard
  Tags: Array, Queue, Sliding Window, Heap (Priority Queue), Monotonic Queue
  Time:
  Space:
*/

class SlidingWindow {
public:
  explicit SlidingWindow(size_t size) : size_(size), comp_() {}

  void Push(ValueType value) {
    if (cnt_ >= size_) {
      while (!deque_.empty() && deque_.front().first <= cnt_ - size_) {
        deque_.pop_front();
      }
    }
    while (!deque_.empty() && !comp_(value, deque_.back().second)) {
      deque_.pop_back();
    }
    deque_.emplace_back(cnt_++, std::move(value));
  }

  const ValueType &Top() const { return deque_.front().second; }

private:
  std::deque<std::pair<size_t, ValueType>> deque_;
  size_t size_;
  size_t cnt_ = 0;
  Comparator comp_;
};

class Solution {
public:
  static std::vector<int> maxSlidingWindow(const std::vector<int> &nums,
                                           int k) {
    SlidingWindow<int> window(k);
    std::vector<int> ans;
    for (int i = 0; i < std::ssize(nums); ++i) {
      window.Push(nums[i]);
      if (i >= k - 1) {
        ans.push_back(window.Top());
      }
    }
    return ans;
  }
};
