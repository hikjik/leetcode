#pragma once

#include <string>
#include <vector>

template <typename OuterIterator> class FlattenIterator {
public:
  using InnerIterator = typename OuterIterator::value_type::const_iterator;
  using reference = typename InnerIterator::reference;
  using pointer = typename InnerIterator::pointer;

  FlattenIterator(OuterIterator outer, OuterIterator outer_end)
      : outer_(outer), outer_end_(outer_end) {
    if (outer_ != outer_end_) {
      inner_ = outer_->cbegin();
    }
  }

  reference operator*() const { return *inner_; }

  pointer operator->() const { return &*inner_; }

  FlattenIterator &operator++() {
    if (++inner_ == outer_->cend()) {
      if (++outer_ != outer_end_) {
        inner_ = outer_->cbegin();
      }
    }
    return *this;
  }

  FlattenIterator operator++(int) {
    FlattenIterator it(*this);
    ++*this;
    return it;
  }

  bool operator==(FlattenIterator other) const {
    if (outer_ != other.outer_) {
      return false;
    }
    if (outer_ != outer_end_ && other.outer_ != other.outer_end_ &&
        inner_ != other.inner_) {
      return false;
    }
    return true;
  }

  bool operator!=(FlattenIterator other) const { return !(*this == other); }

private:
  OuterIterator outer_, outer_end_;
  InnerIterator inner_;
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
    auto range1 = FlattenRange(words1);
    auto range2 = FlattenRange(words2);
    auto it1 = range1.begin(), it2 = range2.begin();
    while (it1 != range1.end() && it2 != range2.end()) {
      if (*it1++ != *it2++) {
        return false;
      }
    }
    return it1 == range1.end() && it2 == range2.end();
  }
};
