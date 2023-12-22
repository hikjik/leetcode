#pragma once

#include <vector>

// Time: O(NM&alpha;(NM))
// Space: O(NM)

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
  static bool containsCycle(const std::vector<std::vector<char>> &grid) {
    const int m = grid.size(), n = grid.back().size();
    DisjointSets sets(m * n);
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (j && grid[i][j] == grid[i][j - 1] &&
            !sets.Merge(i * n + j, i * n + j - 1)) {
          return true;
        }
        if (i && grid[i][j] == grid[i - 1][j] &&
            !sets.Merge(i * n + j, (i - 1) * n + j)) {
          return true;
        }
      }
    }
    return false;
  }
};
