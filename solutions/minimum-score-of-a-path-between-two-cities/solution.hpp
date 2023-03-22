#pragma once

#include <algorithm>
#include <limits>
#include <vector>

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
  static int minScore(int n, const std::vector<std::vector<int>> &roads) {
    DisjointSets disjoin_sets(n);
    for (const auto &road : roads) {
      disjoin_sets.Merge(road[0] - 1, road[1] - 1);
    }

    auto score = std::numeric_limits<int>::max();
    for (const auto &road : roads) {
      if (disjoin_sets.Parent(0) == disjoin_sets.Parent(road[0] - 1)) {
        score = std::min(score, road[2]);
      }
    }
    return score;
  }
};
