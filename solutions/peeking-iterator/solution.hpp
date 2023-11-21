#pragma once

#include <optional>
#include <vector>

// Time: O(1)
// Space: O(1)

class Iterator {
public:
  Iterator(const std::vector<int> &nums)
      : begin(nums.begin()), end(nums.end()) {}

  Iterator(const Iterator &iter) : begin(iter.begin), end(iter.end) {}

  // Returns the next element in the iteration.
  int next() { return *begin++; }

  // Returns true if the iteration has more elements.
  bool hasNext() const { return begin != end; }

private:
  std::vector<int>::const_iterator begin, end;
};

class PeekingIterator : public Iterator {
public:
  PeekingIterator(const std::vector<int> &nums) : Iterator(nums) {}

  int peek() { return Iterator(*this).next(); }
};
