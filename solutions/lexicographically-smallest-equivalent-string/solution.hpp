#pragma once

#include <array>
#include <string>
#include <vector>

// N is the length of the string s1
// M is the length of the string baseStr
// Time: O(N + M)
// Space: O(1)

class DisjointSets {
public:
  explicit DisjointSets(size_t size) : sets_(size), count_(size) {
    for (size_t i = 0; i < sets_.size(); ++i) {
      sets_[i].parent = i;
      sets_[i].min = i;
    }
  }

  size_t Count() { return count_; }

  size_t Parent(size_t i) {
    if (sets_[i].parent != i) {
      sets_[i].parent = Parent(sets_[i].parent);
    }
    return sets_[i].parent;
  }

  size_t Min(size_t i) { return sets_[Parent(i)].min; }

  bool Merge(size_t u, size_t v) {
    size_t i = Parent(u), j = Parent(v);
    if (i == j) {
      return false;
    }
    count_--;

    if (sets_[i].rank > sets_[j].rank) {
      sets_[j].parent = i;
      sets_[i].min = std::min(sets_[i].min, sets_[j].min);
    } else {
      sets_[i].parent = j;
      sets_[j].min = std::min(sets_[i].min, sets_[j].min);
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
    size_t min;
  };

  std::vector<DisjointSetsElement> sets_;
  size_t count_;
};

class Solution {
public:
  static std::string smallestEquivalentString(std::string s1, std::string s2,
                                              std::string baseStr) {
    DisjointSets sets(26);
    for (int i = 0; i < std::ssize(s1); ++i) {
      sets.Merge(s1[i] - 'a', s2[i] - 'a');
    }

    std::string ans(baseStr.size(), 'a');
    for (int i = 0; i < std::ssize(baseStr); ++i) {
      ans[i] += sets.Min(baseStr[i] - 'a');
    }
    return ans;
  }
};
