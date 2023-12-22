#pragma once

#include <vector>

// Time: O(NMK a(NM))
// Space: O(NM)

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

  int Size(int i) { return sets_[Parent(i)].size; }

  bool Merge(int u, int v) {
    int i = Parent(u), j = Parent(v);
    if (i == j) {
      return false;
    }
    count_--;

    if (sets_[i].rank > sets_[j].rank) {
      sets_[j].parent = i;
      sets_[i].size += sets_[j].size;
    } else {
      sets_[i].parent = j;
      sets_[j].size += sets_[i].size;
      if (sets_[i].rank == sets_[j].rank) {
        ++sets_[j].rank;
      }
    }
    return true;
  }

private:
  struct DisjointSetsElement {
    DisjointSetsElement() : parent(0), rank(0), size(1) {}

    int parent;
    int rank;
    int size;
  };

  std::vector<DisjointSetsElement> sets_;
  int count_;
};

class Solution {
public:
  static std::vector<int> hitBricks(std::vector<std::vector<int>> grid,
                                    const std::vector<std::vector<int>> &hits) {
    const int m = grid.size(), n = grid.back().size();
    for (int k = hits.size() - 1; k >= 0; --k) {
      const auto i = hits[k][0], j = hits[k][1];
      if (grid[i][j]) {
        grid[i][j] = -1;
      }
    }

    DisjointSets sets(m * n + 1);
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (grid[i][j] == 1) {
          mergeNeighbors(i, j, grid, &sets);
        }
      }
    }

    std::vector<int> ans(hits.size());
    for (int k = hits.size() - 1; k >= 0; --k) {
      const auto i = hits[k][0], j = hits[k][1];
      if (grid[i][j] == -1) {
        grid[i][j] = 1;
        const auto stable = sets.Size(m * n);
        mergeNeighbors(i, j, grid, &sets);
        ans[k] = std::max(0, sets.Size(m * n) - stable - 1);
      }
    }
    return ans;
  }

private:
  static void mergeNeighbors(int i, int j,
                             const std::vector<std::vector<int>> &grid,
                             DisjointSets *sets) {
    static const std::vector<std::pair<int, int>> kDirs{
        {-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    const int m = grid.size(), n = grid.back().size();

    if (!i) {
      sets->Merge(i * n + j, m * n);
    }
    for (const auto &[di, dj] : kDirs) {
      const auto r = i + di, c = j + dj;
      if (r >= 0 && r < m && c >= 0 && c < n && grid[r][c] == 1) {
        sets->Merge(i * n + j, r * n + c);
      }
    }
  }
};
