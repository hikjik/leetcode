#pragma once

#include <numeric>
#include <queue>
#include <ranges>
#include <vector>

#include <tree_node.h>

// Time: O(NlogN)
// Space: O(N)

namespace pq {

// Time: O(NlogK)
// Space: O(N+K)
class Solution {
public:
  static long long kthLargestLevelSum(TreeNode *root, int k) {
    std::queue<TreeNode *> queue{{root}};
    std::priority_queue<long long, std::vector<long long>, std::greater<>>
        minHeap;
    while (!queue.empty()) {
      long long sum = 0;
      for (int sz = queue.size(); sz; --sz) {
        const auto *node = queue.front();
        queue.pop();

        sum += node->val;

        for (auto *child : {node->left, node->right}) {
          if (child) {
            queue.push(child);
          }
        }
      }
      minHeap.push(sum);
      if (std::ssize(minHeap) > k) {
        minHeap.pop();
      }
    }
    return std::ssize(minHeap) < k ? -1 : minHeap.top();
  }
};

} // namespace pq

namespace bfs {

// Time: O(NlogN) at worst case
// Space: O(N)
class Solution {
public:
  static long long kthLargestLevelSum(TreeNode *root, int k) {
    std::vector<TreeNode *> level{{root}};
    std::vector<long long> sums;
    while (!level.empty()) {
      long long sum = 0;
      std::vector<TreeNode *> nextLevel;
      for (auto *node : level) {
        sum += node->val;

        for (auto *child : {node->left, node->right}) {
          if (child) {
            nextLevel.push_back(child);
          }
        }
      }
      level.swap(nextLevel);
      sums.push_back(sum);
    }
    if (std::ssize(sums) < k) {
      return -1;
    }
    std::ranges::nth_element(sums, sums.begin() + k - 1, std::greater{});
    return sums[k - 1];
  }
};

} // namespace bfs

namespace dfs {

// Time: O(NlogN) at worst case
// Space: O(N)
class Solution {
public:
  static long long kthLargestLevelSum(TreeNode *root, int k) {
    std::vector<long long> sums;
    dfs(root, 0, &sums);
    if (std::ssize(sums) < k) {
      return -1;
    }
    std::ranges::nth_element(sums, sums.begin() + k - 1, std::greater{});
    return sums[k - 1];
  }

  static void dfs(TreeNode *node, int level, std::vector<long long> *sums) {
    if (!node) {
      return;
    }
    if (std::ssize(*sums) == level) {
      sums->push_back(0);
    }
    (*sums)[level] += node->val;
    dfs(node->left, level + 1, sums);
    dfs(node->right, level + 1, sums);
  }
};

} // namespace dfs
