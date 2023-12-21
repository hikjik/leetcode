#pragma once

#include <string>
#include <vector>

// Time: O(N)
// Space: O(A)

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
  static bool equationsPossible(const std::vector<std::string> &equations) {
    DisjointSets sets(26);
    for (const auto &equation : equations) {
      if (equation[1] == '=') {
        sets.Merge(equation[0] - 'a', equation[3] - 'a');
      }
    }
    for (const auto &equation : equations) {
      if (equation[1] == '!' &&
          sets.Parent(equation[0] - 'a') == sets.Parent(equation[3] - 'a')) {
        return false;
      }
    }
    return true;
  }
};
