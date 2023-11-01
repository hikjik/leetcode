#pragma once

#include <vector>

/*
  1971. Find if Path Exists in Graph
  https://leetcode.com/problems/find-if-path-exists-in-graph/
  Difficulty: Easy
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
  static bool validPath(int n, const std::vector<std::vector<int>> &edges,
                        int source, int destination) {
    DisjointSets sets(n);
    for (const auto &edge : edges) {
      sets.Merge(edge[0], edge[1]);
    }
    return sets.Parent(source) == sets.Parent(destination);
  }
};
