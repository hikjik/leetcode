#pragma once

#include <queue>
#include <vector>

// Time: O(NM)
// Space: O(NM)

class DisjointSets {
public:
  explicit DisjointSets(int size) : sets_(size), count_(size) {
    for (int i = 0; i < size; ++i) {
      sets_[i].parent = i;
      sets_[i].max = i;
    }
  }

  int Count() { return count_; }

  int Parent(int i) {
    if (sets_[i].parent != i) {
      sets_[i].parent = Parent(sets_[i].parent);
    }
    return sets_[i].parent;
  }

  int Max(int i) { return sets_[Parent(i)].max; }

  bool Merge(int u, int v) {
    int i = Parent(u), j = Parent(v);
    if (i == j) {
      return false;
    }
    count_--;

    if (sets_[i].rank > sets_[j].rank) {
      sets_[j].parent = i;
      sets_[i].max = std::max(sets_[i].max, sets_[j].max);
    } else {
      sets_[i].parent = j;
      sets_[j].max = std::max(sets_[i].max, sets_[j].max);
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
    int max;
  };

  std::vector<DisjointSetsElement> sets_;
  int count_;
};

class Solution {
public:
  static int minimumVisitedCells(const std::vector<std::vector<int>> &grid) {
    const int m = grid.size(), n = grid.back().size();

    std::vector<DisjointSets> rows(m, DisjointSets(n));
    std::vector<DisjointSets> cols(n, DisjointSets(m));

    std::queue<std::pair<int, int>> queue{{{0, 0}}};
    for (int steps = 0; !queue.empty(); ++steps) {
      for (int sz = queue.size(); sz; --sz) {
        const auto [i, j] = queue.front();
        queue.pop();

        if (i == m - 1 && j == n - 1) {
          return steps + 1;
        }

        while (rows[i].Max(j) < std::min(n - 1, grid[i][j] + j)) {
          queue.push({i, rows[i].Max(j) + 1});
          rows[i].Merge(j, rows[i].Max(j) + 1);
        }

        while (cols[j].Max(i) < std::min(m - 1, grid[i][j] + i)) {
          queue.push({cols[j].Max(i) + 1, j});
          cols[j].Merge(i, cols[j].Max(i) + 1);
        }
      }
    }

    return -1;
  }
};
