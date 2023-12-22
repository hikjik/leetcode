#pragma once

#include <ranges>
#include <vector>

// M = max(nums)
// Time: O(NM^(0.5)&alpha;(M))
// Space: O(M)

class DisjointSets {
public:
  explicit DisjointSets(int size) : sets_(size), count_(size) {
    for (int i = 0; i < std::ssize(sets_); ++i) {
      sets_[i].parent = i;
    }
  }

  int Count() { return count_; }

  int Parent(int i) {
    if (sets_[i].parent != i) {
      sets_[i].parent = Parent(sets_[i].parent);
    }
    return sets_[i].parent;
  }

  bool Merge(int u, int v) {
    int i = Parent(u), j = Parent(v);
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

    int parent;
    int rank;
  };

  std::vector<DisjointSetsElement> sets_;
  int count_;
};

class Solution {
public:
  static bool gcdSort(const std::vector<int> &nums) {
    DisjointSets sets(std::ranges::max(nums) + 1);
    for (auto num : nums) {
      for (int i = 2; i * i <= num; ++i) {
        if (num % i == 0) {
          sets.Merge(num, i);
          sets.Merge(num, num / i);
        }
      }
    }

    auto sorted = nums;
    std::ranges::sort(sorted);

    for (int i = 0; i < std::ssize(nums); ++i) {
      if (sets.Parent(nums[i]) != sets.Parent(sorted[i])) {
        return false;
      }
    }
    return true;
  }
};
