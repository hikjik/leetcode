#pragma once

#include <unordered_map>
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
  static long long countPairs(int n,
                              const std::vector<std::vector<int>> &edges) {
    DisjointSets sets(n);
    for (const auto &edge : edges) {
      sets.Merge(edge[0], edge[1]);
    }

    std::unordered_map<int, int> counter;
    for (int i = 0; i < n; ++i) {
      counter[sets.Parent(i)]++;
    }

    long long total = 0;
    long long sum = 0;
    for (const auto &[parent, cnt] : counter) {
      total += sum * cnt;
      sum += cnt;
    }
    return total;
  }
};
