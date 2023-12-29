#pragma once

#include <vector>

// Time: O(NlogN+Q)
// Space: O(N)

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
  static std::vector<bool>
  areConnected(int n, int threshold,
               const std::vector<std::vector<int>> &queries) {
    DisjointSets sets(n + 1);
    for (int d = threshold + 1; d <= n; ++d) {
      for (int i = 2 * d; i <= n; i += d) {
        sets.Merge(d, i);
      }
    }

    std::vector<bool> ans;
    for (const auto &query : queries) {
      ans.push_back(sets.Parent(query[0]) == sets.Parent(query[1]));
    }
    return ans;
  }
};
