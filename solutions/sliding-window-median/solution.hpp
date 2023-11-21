#pragma once

#include <queue>
#include <set>
#include <vector>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

template <class T>
using ordered_multiset = tree<T, null_type, std::less_equal<T>, rb_tree_tag,
                              tree_order_statistics_node_update>;

// Time: O(NlogK)
// Space: O(K)

namespace oset {

class SlidingWindowMedian {
public:
  explicit SlidingWindowMedian(int size) : size(size) {}

  void push(int value) { set.insert(value); }

  void erase(int value) { set.erase(set.upper_bound(value)); }

  double median() const {
    const auto it = set.find_by_order((size - 1) / 2);
    return size & 1 ? *it : (*it * 1.0 + *std::next(it)) / 2;
  }

private:
  ordered_multiset<int> set;
  int size;
};

// Time: O(NlogK)
// Space: O(K)
class Solution {
public:
  static std::vector<double> medianSlidingWindow(const std::vector<int> &nums,
                                                 int k) {
    std::vector<double> ans;
    SlidingWindowMedian window(k);
    for (int i = 0; i < std::ssize(nums); ++i) {
      if (i >= k) {
        window.erase(nums[i - k]);
      }
      window.push(nums[i]);
      if (i >= k - 1) {
        ans.push_back(window.median());
      }
    }
    return ans;
  }
};

} // namespace oset

namespace two_multiset {

class SlidingWindowMedian {
public:
  explicit SlidingWindowMedian(int size) : size(size) {}

  void push(int value) {
    if (low.empty()) {
      low.insert(value);
      return;
    }
    if (*low.rbegin() < value) {
      up.insert(value);
      if (std::ssize(up) > size / 2) {
        low.insert(*up.begin());
        up.erase(up.begin());
      }
    } else {
      low.insert(value);
      if (std::ssize(low) > (size + 1) / 2) {
        up.insert(*low.rbegin());
        low.erase(std::prev(low.end()));
      }
    }
  }

  void erase(int value) {
    if (auto it = up.find(value); it != up.end()) {
      up.erase(it);
    } else {
      low.erase(low.find(value));
    }

    if (low.empty() && !up.empty()) {
      low.insert(*up.begin());
      up.erase(up.begin());
    }
  }

  double median() const {
    return size & 1 ? *low.rbegin() : (*low.rbegin() * 1.0 + *up.begin()) / 2;
  }

private:
  std::multiset<int> low;
  std::multiset<int> up;
  int size;
};

// Time: O(NlogK)
// Space: O(K)
class Solution {
public:
  static std::vector<double> medianSlidingWindow(const std::vector<int> &nums,
                                                 int k) {
    std::vector<double> ans;
    SlidingWindowMedian window(k);
    for (int i = 0; i < std::ssize(nums); ++i) {
      if (i >= k) {
        window.erase(nums[i - k]);
      }
      window.push(nums[i]);
      if (i >= k - 1) {
        ans.push_back(window.median());
      }
    }
    return ans;
  }
};

} // namespace two_multiset

namespace multiset {

class SlidingWindowMedian {
public:
  explicit SlidingWindowMedian(int size) : size(size) {}

  void push(int value) {
    set.insert(value);
    if (index == size - 1) {
      it = std::next(set.begin(), (size - 1) / 2);
    }
    if (index >= size) {
      if (it == set.end() || value < *it) {
        --it;
      }
    }
    ++index;
  }

  void erase(int value) {
    if (value <= *it) {
      ++it;
    }
    set.erase(set.lower_bound(value));
  }

  double median() const {
    return size & 1 ? *it : (*it * 1.0 + *std::next(it)) / 2;
  }

private:
  std::multiset<int> set;
  std::multiset<int>::iterator it;
  int size;
  int index = 0;
};

// Time: O(NlogK)
// Space: O(K)
class Solution {
public:
  static std::vector<double> medianSlidingWindow(const std::vector<int> &nums,
                                                 int k) {
    std::vector<double> ans;
    SlidingWindowMedian window(k);
    for (int i = 0; i < std::ssize(nums); ++i) {
      if (i >= k) {
        window.erase(nums[i - k]);
      }
      window.push(nums[i]);
      if (i >= k - 1) {
        ans.push_back(window.median());
      }
    }
    return ans;
  }
};

} // namespace multiset

namespace heap {

class SlidingWindowMedian {
public:
  explicit SlidingWindowMedian(int size) : size(size) {}

  void push(int value) {
    skip();
    if (balance < (size + 1) / 2) {
      minHeap.push({value, index});
      maxHeap.push(minHeap.top());
      minHeap.pop();
      ++balance;
    } else {
      maxHeap.push({value, index});
      minHeap.push(maxHeap.top());
      maxHeap.pop();
    }
    skip();
    ++index;
  }

  void erase(int value) {
    if (value <= maxHeap.top().first) {
      --balance;
    }
  }

  double median() const {
    return size & 1 ? maxHeap.top().first
                    : (maxHeap.top().first * 1.0 + minHeap.top().first) / 2;
  }

private:
  using Item = std::pair<int, int>;

  void skip() {
    while (!minHeap.empty() && minHeap.top().second <= index - size) {
      minHeap.pop();
    }
    while (!maxHeap.empty() && maxHeap.top().second <= index - size) {
      maxHeap.pop();
    }
  }

  std::priority_queue<Item> maxHeap;
  std::priority_queue<Item, std::vector<Item>, std::greater<>> minHeap;
  int size;
  int index = 0;
  int balance = 0;
};

// Time: O(NlogK)
// Space: O(K)
class Solution {
public:
  static std::vector<double> medianSlidingWindow(const std::vector<int> &nums,
                                                 int k) {
    std::vector<double> ans;
    SlidingWindowMedian window(k);
    for (int i = 0; i < std::ssize(nums); ++i) {
      if (i >= k) {
        window.erase(nums[i - k]);
      }
      window.push(nums[i]);
      if (i >= k - 1) {
        ans.push_back(window.median());
      }
    }
    return ans;
  }
};

} // namespace heap
