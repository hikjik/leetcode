#pragma once

#include <string>
#include <vector>

// Time: O(N^2)
// Space: O(N^2)

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
  static int regionsBySlashes(const std::vector<std::string> &grid) {
    const int n = grid.size();
    DisjointSets sets(4 * n * n);
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        const auto r = 4 * n * i, c = 4 * j;
        if (i) {
          sets.Merge(r + c, (r - 4 * n) + c + 2);
        }
        if (j) {
          sets.Merge(r + c + 3, r + (c - 4) + 1);
        }
        if (grid[i][j] == '/' || grid[i][j] == ' ') {
          sets.Merge(r + c, r + c + 3);
          sets.Merge(r + c + 1, r + c + 2);
        }
        if (grid[i][j] == '\\' || grid[i][j] == ' ') {
          sets.Merge(r + c, r + c + 1);
          sets.Merge(r + c + 2, r + c + 3);
        }
      }
    }
    return sets.Count();
  }
};
