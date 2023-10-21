#pragma once

#include <climits>
#include <queue>
#include <vector>

template <typename ValueType, typename Comparator = std::less<>>
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
  static int constrainedSubsetSum(const std::vector<int> &nums, int k) {
    SlidingWindow<int> window(k);
    window.Push(0);

    int ans = INT_MIN;
    for (auto a : nums) {
      const auto max = std::max(a, a + window.Top());
      ans = std::max(ans, max);
      window.Push(max);
    }
    return ans;
  }
};
