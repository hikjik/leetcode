#pragma once

#include <algorithm>
#include <vector>

/*
  1697. Checking Existence of Edge Length Limited Paths
  https://leetcode.com/problems/checking-existence-of-edge-length-limited-paths/
  Difficulty: Hard
  Tags: Array, Two Pointers, Union Find, Graph, Sorting
  Time:
  Space:
*/

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

  void Merge(size_t u, size_t v) {
    size_t i = Parent(u), j = Parent(v);
    if (i == j) {
      return;
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
  distanceLimitedPathsExist(int n, std::vector<std::vector<int>> edges,
                            std::vector<std::vector<int>> queries) {
    auto compare = [](const std::vector<int> &lhs,
                      const std::vector<int> &rhs) { return lhs[2] < rhs[2]; };
    for (size_t i = 0; i < queries.size(); ++i) {
      queries[i].push_back(i);
    }
    std::sort(queries.begin(), queries.end(), compare);
    std::sort(edges.begin(), edges.end(), compare);

    DisjointSets sets(n);
    std::vector<bool> exists(queries.size(), false);
    size_t i = 0;
    for (const auto &query : queries) {
      while (i < edges.size() && edges[i][2] < query[2]) {
        sets.Merge(edges[i][0], edges[i][1]);
        i++;
      }
      exists[query[3]] = sets.Parent(query[0]) == sets.Parent(query[1]);
    }
    return exists;
  }
};
