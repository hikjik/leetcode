#pragma once

#include <vector>

class DisjointSets {
public:
  explicit DisjointSets(int size) : parents_(size), count_(size) {
    for (int i = 0; i < size; ++i) {
      parents_[i] = i;
    }
  }

  int Count() { return count_; }

  int Parent(int i) {
    if (parents_[i] != i) {
      parents_[i] = Parent(parents_[i]);
    }
    return parents_[i];
  }

  bool Merge(int parent, int child) {
    if (child != Parent(child) || Parent(child) == Parent(parent)) {
      return false;
    }

    --count_;
    parents_[Parent(child)] = Parent(parent);
    return true;
  }

private:
  std::vector<int> parents_;
  int count_;
};

class Solution {
public:
  static bool validateBinaryTreeNodes(int n, const std::vector<int> &left,
                                      const std::vector<int> &right) {
    DisjointSets sets(n);
    for (const auto &children : {left, right}) {
      for (int parent = 0; parent < n; ++parent) {
        const auto child = children[parent];
        if (child != -1 && !sets.Merge(parent, child)) {
          return false;
        }
      }
    }
    return sets.Count() == 1;
  }
};
