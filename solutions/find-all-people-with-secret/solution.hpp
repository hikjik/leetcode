#pragma once

#include <ranges>
#include <unordered_set>
#include <vector>

// Time: O(MlogM+MN&alpha;(N))
// Space: O(N+M)

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

  void Reset(int i) {
    sets_[i].parent = i;
    sets_[i].rank = 0;
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
  static std::vector<int> findAllPeople(int n,
                                        std::vector<std::vector<int>> meetings,
                                        int firstPerson) {
    const int m = meetings.size();
    std::ranges::sort(meetings, [](const auto &lhs, const auto &rhs) {
      return lhs.back() < rhs.back();
    });

    DisjointSets sets(n);
    sets.Merge(0, firstPerson);

    for (int i = 0; i < m; ++i) {
      int j = i;
      while (j < m && meetings[j][2] == meetings[i][2]) {
        sets.Merge(meetings[j][0], meetings[j][1]);
        ++j;
      }
      for (int k = i; k < j; ++k) {
        if (sets.Parent(0) != sets.Parent(meetings[k][0])) {
          sets.Reset(meetings[k][0]);
          sets.Reset(meetings[k][1]);
        }
      }
      i = j - 1;
    }

    std::vector<int> ans;
    for (int i = 0; i < n; ++i) {
      if (sets.Parent(0) == sets.Parent(i)) {
        ans.push_back(i);
      }
    }
    return ans;
  }
};
