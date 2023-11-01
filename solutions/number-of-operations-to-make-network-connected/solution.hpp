#pragma once

#include <unordered_set>
#include <vector>

/*
  1319. Number of Operations to Make Network Connected
  https://leetcode.com/problems/number-of-operations-to-make-network-connected/
  Difficulty: Medium
  Tags: Depth-First Search, Breadth-First Search, Union Find, Graph
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
  static int makeConnected(int n,
                           const std::vector<std::vector<int>> &connections) {
    int m = connections.size();
    if (m < n - 1) {
      return -1;
    }

    DisjointSets disjoin_sets(n);
    for (const auto &connection : connections) {
      disjoin_sets.Merge(connection[0], connection[1]);
    }
    return disjoin_sets.Count() - 1;
  }
};
