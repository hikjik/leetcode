#pragma once

#include <list>
#include <queue>
#include <vector>

// Time: O(Q)
// Space: O(1)

namespace lst {

// Space: O(1)
class ZigzagIterator {
public:
  // O(1)
  ZigzagIterator(const std::vector<int> &v1, const std::vector<int> &v2) {
    if (!v1.empty()) {
      list.push_back({v1.begin(), v1.end()});
    }
    if (!v2.empty()) {
      list.push_back({v2.begin(), v2.end()});
    }
    curr = list.begin();
  }

  // O(1)
  int next() {
    const auto value = *curr->begin;
    ++curr->begin;
    if (curr->empty()) {
      curr = list.erase(curr);
    } else {
      ++curr;
    }
    if (curr == list.end()) {
      curr = list.begin();
    }
    return value;
  }

  // O(1)
  bool hasNext() const { return !list.empty(); }

private:
  template <typename Iterator> struct Range {
    Range(Iterator begin, Iterator end) : begin(begin), end(end) {}

    bool empty() const { return begin == end; }

    Iterator begin, end;
  };

  using Iterator = std::vector<int>::const_iterator;

  std::list<Range<Iterator>> list;
  std::list<Range<Iterator>>::iterator curr;
};

} // namespace lst

namespace queue {

// Space: O(1)
class ZigzagIterator {
public:
  // O(1)
  ZigzagIterator(const std::vector<int> &v1, const std::vector<int> &v2) {
    if (!v1.empty()) {
      queue.push({v1.begin(), v1.end()});
    }
    if (!v2.empty()) {
      queue.push({v2.begin(), v2.end()});
    }
  }

  // O(1)
  int next() {
    const auto [begin, end] = queue.front();
    queue.pop();
    if (begin + 1 != end) {
      queue.push({begin + 1, end});
    }
    return *begin;
  }

  // O(1)
  bool hasNext() const { return !queue.empty(); }

private:
  template <typename Iterator> struct Range {
    Range(Iterator begin, Iterator end) : begin(begin), end(end) {}

    bool empty() const { return begin == end; }

    Iterator begin, end;
  };

  using Iterator = std::vector<int>::const_iterator;

  std::queue<Range<Iterator>> queue;
};

} // namespace queue
