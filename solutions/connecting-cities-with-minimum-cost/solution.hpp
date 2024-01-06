#pragma once

#include <ranges>
#include <vector>

// Time: O(MlogM+M&alpha;(N))
// Space: O(N+M)

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
  static int minimumCost(int n, std::vector<std::vector<int>> connections) {
    std::ranges::sort(connections, [](const auto &lhs, const auto &rhs) {
      return lhs.back() < rhs.back();
    });
    DisjointSets sets(n);
    int ans = 0;
    for (const auto &connection : connections) {
      if (sets.Merge(connection[0] - 1, connection[1] - 1)) {
        ans += connection[2];
      }
    }
    return sets.Count() == 1 ? ans : -1;
  }
};
