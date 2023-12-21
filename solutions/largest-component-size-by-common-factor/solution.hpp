#pragma once

#include <unordered_map>
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
  static int largestComponentSize(const std::vector<int> &nums) {
    const int n = std::ranges::max(nums);
    DisjointSets sets(n + 1);
    for (auto num : nums) {
      for (int d = 2; d * d <= num; ++d) {
        if (num % d == 0) {
          sets.Merge(num, d);
          sets.Merge(num, num / d);
        }
      }
    }

    int ans = 0;
    std::vector<int> cnt(n + 1);
    for (auto num : nums) {
      ans = std::max(ans, ++cnt[sets.Parent(num)]);
    }
    return ans;
  }
};
