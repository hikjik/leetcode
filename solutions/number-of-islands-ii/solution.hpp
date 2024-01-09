#pragma once

#include <vector>

// Time: O(MN+T&alpha;(MN))
// Space: O(MN)

class DisjointSets {
public:
  explicit DisjointSets(int size) : sets_(size), count_(0) {
    for (auto &set : sets_) {
      set.parent = -1;
    }
  }

  int Count() const { return count_; }

  void Set(int i) {
    if (!IsSet(i)) {
      ++count_;
      sets_[i].parent = i;
    }
  }

  bool IsSet(int i) const { return sets_[i].parent != -1; }

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
  static std::vector<int>
  numIslands2(int m, int n, const std::vector<std::vector<int>> &positions) {
    static const std::vector<std::pair<int, int>> kDirs{
        {-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    DisjointSets sets(m * n);
    std::vector<int> ans;
    for (const auto &position : positions) {
      const auto i = position[0], j = position[1];
      sets.Set(i * n + j);
      for (const auto &[di, dj] : kDirs) {
        const int r = i + di, c = j + dj;
        if (0 <= r && r < m && 0 <= c && c < n && sets.IsSet(r * n + c)) {
          sets.Merge(i * n + j, r * n + c);
        }
      }
      ans.push_back(sets.Count());
    }
    return ans;
  }
};
