#pragma once

#include <algorithm>
#include <climits>
#include <vector>

// Time:
// Space:

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
  static std::vector<std::vector<int>>
  findCriticalAndPseudoCriticalEdges(int n,
                                     std::vector<std::vector<int>> edges) {
    for (size_t i = 0; i < edges.size(); ++i) {
      edges[i].push_back(i);
    }

    std::sort(edges.begin(), edges.end(),
              [](const auto &lhs, const auto &rhs) { return lhs[2] < rhs[2]; });

    const auto mst_weight = computeMSTWeight(n, edges, {}, -1);
    std::vector<int> critical_edges, pseudo_critical_edges;
    for (const auto &edge : edges) {
      if (mst_weight < computeMSTWeight(n, edges, {}, edge[3])) {
        critical_edges.push_back(edge[3]);
      } else if (mst_weight == computeMSTWeight(n, edges, edge, -1)) {
        pseudo_critical_edges.push_back(edge[3]);
      }
    }

    return {critical_edges, pseudo_critical_edges};
  }

private:
  static int computeMSTWeight(int n, const std::vector<std::vector<int>> &edges,
                              const std::vector<int> &forced_edge,
                              int exclude_index) {
    int mst_weight = 0;
    DisjointSets sets(n);

    if (!forced_edge.empty()) {
      sets.Merge(forced_edge[0], forced_edge[1]);
      mst_weight += forced_edge[2];
    }

    for (const auto &edge : edges) {
      if (edge[3] == exclude_index) {
        continue;
      }

      if (sets.Merge(edge[0], edge[1])) {
        mst_weight += edge[2];
      }
    }

    return sets.Count() == 1 ? mst_weight : INT_MAX;
  }
};
