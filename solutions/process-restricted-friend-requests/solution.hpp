#pragma once

#include <ranges>
#include <vector>

// R = requests.size()
// B = restrictions.size()
// Time: O(RB&alpha;(N))
// Space: O(N)

class DisjointSets {
public:
  explicit DisjointSets(int size) : sets_(size), count_(size) {
    for (int i = 0; i < std::ssize(sets_); ++i) {
      sets_[i].parent = i;
    }
  }

  int Count() { return count_; }

  int Parent(int i) {
    if (sets_[i].parent != i) {
      sets_[i].parent = Parent(sets_[i].parent);
    }
    return sets_[i].parent;
  }

  bool Merge(int u, int v) {
    int i = Parent(u), j = Parent(v);
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

    int parent;
    int rank;
  };

  std::vector<DisjointSetsElement> sets_;
  int count_;
};

class Solution {
public:
  static std::vector<bool>
  friendRequests(int n, const std::vector<std::vector<int>> &restrictions,
                 const std::vector<std::vector<int>> &requests) {
    DisjointSets sets(n);
    std::vector<bool> ans;
    for (const auto &r : requests) {
      if (sets.Parent(r[0]) != sets.Parent(r[1])) {
        ans.push_back(std::ranges::none_of(restrictions, [&](const auto &s) {
          return sets.Parent(s[0]) == sets.Parent(r[0]) &&
                     sets.Parent(s[1]) == sets.Parent(r[1]) ||
                 sets.Parent(s[0]) == sets.Parent(r[1]) &&
                     sets.Parent(s[1]) == sets.Parent(r[0]);
        }));
        if (ans.back()) {
          sets.Merge(r[0], r[1]);
        }
      } else {
        ans.push_back(true);
      }
    }
    return ans;
  }
};
