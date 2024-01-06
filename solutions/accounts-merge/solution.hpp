#pragma once

#include <ranges>
#include <string>
#include <string_view>
#include <unordered_map>
#include <vector>

// Time: O(NKlogNK+NK&alpha;(N))
// Space: O(NK)

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
  static std::vector<std::vector<std::string>>
  accountsMerge(const std::vector<std::vector<std::string>> &accounts) {
    DisjointSets sets(accounts.size());
    std::unordered_map<std::string_view, int> emailToAccountId;
    for (int i = 0; i < std::ssize(accounts); ++i) {
      for (int j = 1; j < std::ssize(accounts[i]); ++j) {
        const auto &email = accounts[i][j];
        if (emailToAccountId.contains(email)) {
          sets.Merge(i, emailToAccountId[email]);
        } else {
          emailToAccountId[email] = i;
        }
      }
    }

    std::unordered_map<int, std::vector<std::string>> groups;
    for (const auto &[email, accountId] : emailToAccountId) {
      groups[sets.Parent(accountId)].emplace_back(email);
    }

    std::vector<std::vector<std::string>> ans;
    for (auto &[groupId, emails] : groups) {
      ans.push_back({accounts[groupId][0]});
      std::ranges::sort(emails);
      std::ranges::copy(std::make_move_iterator(emails.begin()),
                        std::make_move_iterator(emails.end()),
                        std::back_inserter(ans.back()));
    }
    return ans;
  }
};
