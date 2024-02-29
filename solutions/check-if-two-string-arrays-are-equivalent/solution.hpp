#pragma once

#include <iterator>
#include <numeric>
#include <string>
#include <vector>

// Time: O(NK)
// Space: O(1)

namespace extra_space {

// Time: O(NK)
// Space: O(NK)
class Solution {
public:
  static bool arrayStringsAreEqual(const std::vector<std::string> &words1,
                                   const std::vector<std::string> &words2) {
    return std::accumulate(words1.begin(), words1.end(), std::string{}) ==
           std::accumulate(words2.begin(), words2.end(), std::string{});
  }
};

} // namespace extra_space

namespace flatten_iterator {

// Time: O(NK)
// Space: O(1)
template <typename OuterIterator> class FlattenIterator {
public:
  using value_type = OuterIterator::value_type::const_iterator::value_type;
  using pointer = value_type *;
  using reference = value_type &;
  using iterator_category = std::input_iterator_tag;
  using difference_type = std::ptrdiff_t;

  FlattenIterator(OuterIterator first, OuterIterator last)
      : first(first), last(last) {
    if (first != last) {
      inner = first->cbegin();
    }
  }

  auto operator*() const { return *inner; }

  FlattenIterator &operator++() {
    if (++inner == first->cend()) {
      if (++first != last) {
        inner = first->cbegin();
      }
    }
    return *this;
  }

  bool operator==(FlattenIterator other) const {
    if (first != other.first) {
      return false;
    }
    if (first != last && other.first != other.last && inner != other.inner) {
      return false;
    }
    return true;
  }

  bool operator!=(FlattenIterator other) const { return !(*this == other); }

private:
  using InnerIterator = typename OuterIterator::value_type::const_iterator;

  OuterIterator first, last;
  InnerIterator inner;
};

template <class Iterator> class Range {
public:
  Range(Iterator begin, Iterator end) : begin_(begin), end_(end) {}

  Iterator begin() const { return begin_; }
  Iterator end() const { return end_; }

private:
  Iterator begin_, end_;
};

template <typename Container> auto FlattenRange(const Container &container) {
  return Range(FlattenIterator(container.cbegin(), container.cend()),
               FlattenIterator(container.cend(), container.cend()));
}

class Solution {
public:
  static bool arrayStringsAreEqual(const std::vector<std::string> &words1,
                                   const std::vector<std::string> &words2) {
    auto r1 = FlattenRange(words1), r2 = FlattenRange(words2);
    return std::equal(r1.begin(), r1.end(), r2.begin(), r2.end());
  }
};

} // namespace flatten_iterator
