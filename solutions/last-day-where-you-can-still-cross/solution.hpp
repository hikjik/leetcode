#pragma once

#include <vector>

class DisjointSets {
public:
  explicit DisjointSets(size_t size) : sets_(size) {
    for (size_t i = 0; i < sets_.size(); ++i) {
      sets_[i].parent = i;
    }
  }

  size_t Parent(size_t i) {
    if (sets_[i].parent != i) {
      sets_[i].parent = Parent(sets_[i].parent);
    }
    return sets_[i].parent;
  }

  void Merge(size_t u, size_t v) {
    size_t i = Parent(u), j = Parent(v);
    if (i == j) {
      return;
    }

    if (sets_[i].rank > sets_[j].rank) {
      sets_[j].parent = i;
    } else {
      sets_[i].parent = j;
      if (sets_[i].rank == sets_[j].rank) {
        ++sets_[j].rank;
      }
    }
  }

private:
  struct DisjointSetsElement {
    DisjointSetsElement() : parent(0), rank(0) {}

    size_t parent;
    size_t rank;
  };

  std::vector<DisjointSetsElement> sets_;
};

class Solution {
public:
  static int latestDayToCross(int row, int col,
                              const std::vector<std::vector<int>> &cells) {
    std::vector<std::pair<int, int>> dirs{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    DisjointSets sets(row * col + 2);
    std::vector grid(row, std::vector<int>(col, 1));

    for (int k = cells.size() - 1; k >= 0; --k) {
      const auto cell = cells[k];

      const auto i = cell[0] - 1, j = cell[1] - 1;
      grid[i][j] = 0;

      for (const auto &[di, dj] : dirs) {
        const auto r = i + di, c = j + dj;
        if (r >= 0 && r < row && c >= 0 && c < col && grid[r][c] == 0) {
          sets.Merge(i * col + j + 1, r * col + c + 1);
        }
      }

      if (i == 0) {
        sets.Merge(0, i * col + j + 1);
      }
      if (i == row - 1) {
        sets.Merge(row * col + 1, i * col + j + 1);
      }

      if (sets.Parent(0) == sets.Parent(row * col + 1)) {
        return k;
      }
    }

    throw;
  }
};
