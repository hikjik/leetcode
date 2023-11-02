#pragma once

#include <string>
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
  static int numSimilarGroups(const std::vector<std::string> &strs) {
    DisjointSets sets(strs.size());
    for (size_t i = 0; i < strs.size(); ++i) {
      for (size_t j = i + 1; j < strs.size(); ++j) {
        if (isSimilar(strs[i], strs[j])) {
          sets.Merge(i, j);
        }
      }
    }
    return sets.Count();
  }

private:
  static bool isSimilar(const std::string &str1, const std::string &str2) {
    int cnt = 0;
    for (size_t i = 0; i < str1.size(); ++i) {
      if (str1[i] != str2[i]) {
        if (++cnt > 2) {
          return false;
        }
      }
    }
    return true;
  }
};
