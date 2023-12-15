#pragma once

#include <bit>
#include <ranges>
#include <unordered_set>
#include <vector>

// N = nums.size(), K = log2(ranges::max(nums))
// Time: O(NK)
// Space: O(N)

namespace bit_trie {

// Time: O(NK)
// Space: O(NK)
struct TrieNode {
  TrieNode *zero = nullptr;
  TrieNode *one = nullptr;

  TrieNode *get(int bit) const { return bit ? one : zero; }
  TrieNode *&get(int bit) { return bit ? one : zero; }
};

class BitTrie : private TrieNode {
public:
  explicit BitTrie(int bitWidth) : bitWidth(bitWidth) {}

  ~BitTrie() { clear(this); }

  void insert(int num) {
    TrieNode *node = this;
    for (int i = bitWidth - 1; i >= 0; --i) {
      const auto bit = num >> i & 1;
      if (!node->get(bit)) {
        node->get(bit) = new TrieNode();
      }
      node = node->get(bit);
    }
  }

  int getMaxXor(int num) const {
    const TrieNode *node = this;
    int maxXor = 0;
    for (int i = bitWidth - 1; i >= 0; --i) {
      const auto bit = num >> i & 1;
      if (node->get(!bit)) {
        maxXor |= 1 << i;
        node = node->get(!bit);
      } else if (node->get(bit)) {
        node = node->get(bit);
      } else {
        return 0;
      }
    }
    return maxXor;
  }

private:
  void clear(TrieNode *node) {
    if (!node) {
      return;
    }
    clear(node->zero);
    clear(node->one);
  }

  int bitWidth;
};

class Solution {
public:
  static int findMaximumXOR(const std::vector<int> &nums) {
    const unsigned max = std::ranges::max(nums);
    BitTrie trie(std::bit_width(max));
    for (auto num : nums) {
      trie.insert(num);
    }
    return std::accumulate(nums.begin(), nums.end(), 0, [&](int a, int b) {
      return std::max(a, trie.getMaxXor(b));
    });
  }
};

} // namespace bit_trie

namespace hash_table {

// Time: O(NK)
// Space: O(N)
class Solution {
public:
  static int findMaximumXOR(const std::vector<int> &nums) {
    const unsigned max = std::ranges::max(nums);
    int ans = 0;
    for (int mask = 0, i = std::bit_width(max) - 1; i >= 0; --i) {
      mask |= 1 << i;
      const auto target = ans | (1 << i);
      std::unordered_set<int> set;
      for (auto num : nums) {
        num &= mask;
        if (set.contains(num ^ target)) {
          ans = target;
          break;
        }
        set.insert(num);
      }
    }
    return ans;
  }
};

} // namespace hash_table
