#pragma once

#include <algorithm>
#include <functional>
#include <iostream>
#include <random>
#include <vector>

template <typename Iterator> struct IteratorRange {
  Iterator left;
  Iterator right;
};

template <typename Iterator, typename RandomGenerator>
Iterator SelectRandomPivot(Iterator begin, Iterator end,
                           RandomGenerator &generator) {
  std::uniform_int_distribution<size_t> distribution(
      0, std::distance(begin, end) - 1);
  auto pivot = begin;
  std::advance(begin, distribution(generator));
  return pivot;
}

template <typename Iterator, typename Comparator = std::less<>>
IteratorRange<Iterator>
Partition3Way(Iterator begin, Iterator end,
              typename std::iterator_traits<Iterator>::value_type pivot_value,
              Comparator comparator = {}) {
  auto middle_first = begin, middle_second = begin;
  for (auto it = begin; it != end; ++it) {
    if (!comparator(pivot_value, *it)) {
      std::iter_swap(middle_second, it);
      if (comparator(*middle_second, pivot_value)) {
        std::iter_swap(middle_first++, middle_second);
      }
      ++middle_second;
    }
  }
  return {middle_first, middle_second};
}

template <typename Iterator, typename RandomGenerator, typename Comparator>
void Sort(Iterator begin, Iterator end, RandomGenerator &generator,
          Comparator comparator) {
  if (begin != end) {
    auto pivot = SelectRandomPivot(begin, end, generator);
    auto range = Partition3Way(begin, end, *pivot, comparator);
    Sort(begin, range.left, generator, comparator);
    Sort(range.right, end, generator, comparator);
  }
}

template <typename Iterator, typename Comparator = std::less<>>
void Sort(Iterator begin, Iterator end, Comparator comparator = {}) {
  std::random_device random_device;
  std::mt19937 generator(random_device());
  Sort(begin, end, generator, comparator);
}

int x = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  return 0;
}();

// Time:
// Space:

class Solution {
public:
  static std::vector<int> sortArray(std::vector<int> nums) {
    std::random_shuffle(nums.begin(), nums.end());
    Sort(nums.begin(), nums.end());
    return nums;
  }
};
