#pragma once

#include <array>
#include <cstring>
#include <memory>
#include <string>
#include <string_view>
#include <unordered_map>
#include <vector>

// N is the number of words
// K is the maximum word length
// A is the size of the alphabet
// Time: O(NK)
// Space: O(N+K)

namespace hash_table {

// Time: O(NK^2)
// Space: O(N+K)
class Solution {
public:
  static std::vector<std::vector<int>>
  palindromePairs(const std::vector<std::string> &words) {
    std::unordered_map<std::string_view, int> map;
    for (int i = 0; i < std::ssize(words); ++i) {
      map[words[i]] = i;
    }

    std::vector<std::vector<int>> ans;
    for (int i = 0; i < std::ssize(words); ++i) {
      const int n = words[i].size();
      const std::string r(words[i].rbegin(), words[i].rend());
      const std::string_view sv(words[i]), rv(r);

      for (int j = 0; j <= n; ++j) {
        if (auto it = map.find(rv.substr(n - j));
            it != map.end() &&
            (j < n && i != it->second || j == n && i < it->second) &&
            isPalindrome(sv.substr(j))) {
          ans.push_back({i, it->second});
        }

        if (auto it = map.find(rv.substr(0, j));
            it != map.end() &&
            (j < n && i != it->second || j == n && i < it->second) &&
            isPalindrome(sv.substr(0, n - j))) {
          ans.push_back({it->second, i});
        }
      }
    }
    return ans;
  }

private:
  static bool isPalindrome(std::string_view s) {
    return std::equal(s.begin(), s.begin() + s.size() / 2, s.rbegin());
  }
};

} // namespace hash_table

namespace rolling_hash {

// Time: O(NK)
// Space: O(N+K)
class Solution {
public:
  static constexpr unsigned long long kPrime = 33;
  static constexpr int kMaxWordLen = 300;

  static std::vector<std::vector<int>>
  palindromePairs(const std::vector<std::string> &words) {
    std::array<unsigned long long, kMaxWordLen + 1> pows{1};
    for (int i = 1; i <= kMaxWordLen; ++i) {
      pows[i] = pows[i - 1] * kPrime;
    }

    std::unordered_map<unsigned long long, int> map;
    for (int i = 0; i < std::ssize(words); ++i) {
      unsigned long long hash = 0;
      for (int j = 0; j < std::ssize(words[i]); ++j) {
        hash = hash * kPrime + words[i][j];
      }
      map[hash] = i;
    }

    std::array<unsigned long long, kMaxWordLen + 1> prefix{}, suffix{};

    std::vector<std::vector<int>> ans;
    for (int i = 0; i < std::ssize(words); ++i) {
      const int n = words[i].size();
      for (int j = 1; j <= n; ++j) {
        prefix[j] = prefix[j - 1] * kPrime + words[i][j - 1];
        suffix[j] = suffix[j - 1] * kPrime + words[i][n - j];
      }

      for (int j = 0; j <= n; ++j) {
        if (prefix[n] - prefix[j] * pows[n - j] == suffix[n - j]) {
          auto it = map.find(suffix[n] - suffix[n - j] * pows[j]);
          if (it != map.end() &&
              (j < n && i != it->second || j == n && i < it->second))
            ans.push_back({i, it->second});
        }
        if (suffix[n] - suffix[j] * pows[n - j] == prefix[n - j]) {
          auto it = map.find(suffix[j]);
          if (it != map.end() &&
              (j < n && i != it->second || j == n && i < it->second))
            ans.push_back({it->second, i});
        }
      }
    }
    return ans;
  }
};

} // namespace rolling_hash

namespace trie {

// Time: O(NK^2)
// Space: O(NKA)
struct TrieNode {
  std::array<std::unique_ptr<TrieNode>, 26> children;
  int idx = -1;
};

class Trie : private TrieNode {
public:
  void insert(std::string_view s, int idx) {
    TrieNode *node = this;
    for (auto c : s) {
      const auto i = c - 'a';
      if (!node->children[i]) {
        node->children[i] = std::make_unique<TrieNode>();
      }
      node = node->children[i].get();
    }
    node->idx = idx;
  }

  int find(std::string_view s) {
    TrieNode *node = this;
    for (int i = 0; node && i < std::ssize(s); ++i) {
      node = node->children[s[i] - 'a'].get();
    }
    return node ? node->idx : -1;
  }
};

class Solution {
public:
  static std::vector<std::vector<int>>
  palindromePairs(const std::vector<std::string> &words) {
    Trie trie;
    for (int i = 0; i < std::ssize(words); ++i) {
      trie.insert(words[i], i);
    }

    std::vector<std::vector<int>> ans;
    for (int i = 0; i < std::ssize(words); ++i) {
      const int n = words[i].size();
      const std::string r(words[i].rbegin(), words[i].rend());
      const std::string_view sv(words[i]), rv(r);

      for (int j = 0; j <= n; ++j) {
        if (auto idx = trie.find(rv.substr(n - j));
            idx != -1 && (j < n && i != idx || j == n && i < idx) &&
            isPalindromic(sv.substr(j))) {
          ans.push_back({i, idx});
        }

        if (auto idx = trie.find(rv.substr(0, j));
            idx != -1 && (j < n && i != idx || j == n && i < idx) &&
            isPalindromic(sv.substr(0, n - j))) {
          ans.push_back({idx, i});
        }
      }
    }
    return ans;
  }

private:
  static bool isPalindromic(std::string_view s) {
    return std::equal(s.begin(), s.begin() + s.size() / 2, s.rbegin());
  }
};

} // namespace trie
