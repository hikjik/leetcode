#pragma once

#include <vector>

/*
  1579. Remove Max Number of Edges to Keep Graph Fully Traversable
  https://leetcode.com/problems/remove-max-number-of-edges-to-keep-graph-fully-traversable/
  Difficulty: Hard
  Tags: Union Find, Graph
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
  static int maxNumEdgesToRemove(int n,
                                 const std::vector<std::vector<int>> &edges) {
    DisjointSets alice(n), bob(n);
    int required_edges = 0;

    for (const auto &edge : edges) {
      int type = edge[0], start = edge[1] - 1, end = edge[2] - 1;
      if (type == 3 && alice.Merge(start, end) | bob.Merge(start, end)) {
        required_edges++;
      }
    }

    for (const auto &edge : edges) {
      int type = edge[0], start = edge[1] - 1, end = edge[2] - 1;
      if (type == 1 && alice.Merge(start, end) ||
          type == 2 && bob.Merge(start, end)) {
        required_edges++;
      }
    }

    if (alice.Count() != 1 || bob.Count() != 1) {
      return -1;
    }
    return edges.size() - required_edges;
  }
};
