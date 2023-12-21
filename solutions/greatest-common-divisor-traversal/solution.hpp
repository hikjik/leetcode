#pragma once

#include <ranges>
#include <vector>

// M = max(nums)
// Time: O(NM^(0.5))
// Space: O(M)

class DisjointSets {
public:
  explicit DisjointSets(size_t size) : sets_(size), count_(size) {
    for (size_t i = 0; i < sets_.size(); ++i) {
      sets_[i].parent = i;
    }
  }

  size_t Count() { return count_; }

  size_t Parent(size_t i) {
    if (sets_[i].parent != i) {
      sets_[i].parent = Parent(sets_[i].parent);
    }
    return sets_[i].parent;
  }

  bool Merge(size_t u, size_t v) {
    size_t i = Parent(u), j = Parent(v);
    if (i == j) {
      return false;
    }
    count_--;

    if (sets_[i].rank > sets_[j].rank) {
      sets_[j].parent = i;
    } else {
      sets_[i].parent = j;
      if (sets_[i].rank == sets_[j].rank) {
        ++sets_[j].rank;
      }
    }
    return true;
  }

private:
  struct DisjointSetsElement {
    DisjointSetsElement() : parent(0), rank(0) {}

    size_t parent;
    size_t rank;
  };

  std::vector<DisjointSetsElement> sets_;
  size_t count_;
};

class Solution {
public:
  static bool canTraverseAllPairs(const std::vector<int> &nums) {
    DisjointSets sets(std::ranges::max(nums) + 1);
    for (auto num : nums) {
      if (num == 1) {
        return nums.size() == 1;
      }

      for (int i = 2; i * i <= num; ++i) {
        if (num % i == 0) {
          sets.Merge(num, i);
          sets.Merge(num, num / i);
        }
      }
    }

    return std::ranges::all_of(nums, [&](int num) {
      return sets.Parent(num) == sets.Parent(nums.front());
    });
  }
};
