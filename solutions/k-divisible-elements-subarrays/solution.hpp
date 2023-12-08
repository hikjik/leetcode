#pragma once

#include <memory>
#include <unordered_map>
#include <unordered_set>
#include <vector>

// Time: O(N^2)
// Space: O(N^2)

namespace trie {

// Time: O(N^2)
// Space: O(N^2)
class Solution {
private:
  struct TrieNode {
    std::unordered_map<int, std::unique_ptr<TrieNode>> children;
  };

public:
  static int countDistinct(const std::vector<int> &nums, int k, int p) {
    const int n = nums.size();
    const auto root = std::make_unique<TrieNode>();

    int ans = 0;
    for (int i = 0; i < n; ++i) {
      auto remain = k;
      auto node = root.get();
      for (int j = i; j < n; ++j) {
        remain -= nums[j] % p == 0;
        if (remain < 0) {
          break;
        }

        if (!node->children.contains(nums[j])) {
          node->children[nums[j]] = std::make_unique<TrieNode>();
          ++ans;
        }
        node = node->children[nums[j]].get();
      }
    }
    return ans;
  }
};

} // namespace trie

namespace hash {

// Time: O(N^2)
// Space: O(N^2)
class Solution {
public:
  static int countDistinct(const std::vector<int> &nums, int k, int p) {
    const int n = nums.size();
    const int base = 211;

    std::vector<unsigned long long> pows(n, 1);
    for (int i = 1; i < n; ++i) {
      pows[i] = pows[i - 1] * base;
    }

    int ans = 0;
    std::unordered_set<unsigned long long> set;
    for (int i = 0; i < n; ++i) {
      unsigned long long hash = 0;
      auto remain = k;
      for (int j = i; j < n; ++j) {
        remain -= nums[j] % p == 0;
        if (remain < 0) {
          break;
        }

        hash += nums[j] * pows[j - i];
        ans += set.insert(hash).second;
      }
    }
    return ans;
  }
};

} // namespace hash
