#pragma once

#include <array>
#include <string>
#include <unordered_map>
#include <vector>

// Time: O(N)
// Space: O(N)

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
  static std::string
  smallestStringWithSwaps(std::string s,
                          const std::vector<std::vector<int>> &pairs) {
    const int n = s.size();
    DisjointSets sets(n);
    for (const auto &p : pairs) {
      sets.Merge(p[0], p[1]);
    }

    std::unordered_map<int, std::vector<int>> groups;
    for (int i = 0; i < n; ++i) {
      groups[sets.Parent(i)].push_back(i);
    }

    std::string ans(n, 'a');
    for (const auto &[_, group] : groups) {
      std::array<int, 26> cnt{};
      for (auto i : group) {
        ++cnt[s[i] - 'a'];
      }
      for (int j = 0; auto i : group) {
        while (!cnt[j]--) {
          ++j;
        }
        ans[i] = 'a' + j;
      }
    }
    return ans;
  }
};
