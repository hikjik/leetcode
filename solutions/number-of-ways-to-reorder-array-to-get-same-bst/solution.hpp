#pragma once

#include <vector>

/*
  1569. Number of Ways to Reorder Array to Get Same BST
  https://leetcode.com/problems/number-of-ways-to-reorder-array-to-get-same-bst/
  Difficulty: Hard
  Tags: Array, Math, Divide and Conquer, Dynamic Programming, Tree, Union Find,
        Binary Search Tree, Memoization, Combinatorics, Binary Tree
  Time:
  Space:
*/

class Solution {
public:
  static int numOfWays(const std::vector<int> &nums) {
    const int n = nums.size();

    std::vector<std::vector<long long>> pascal(n);
    for (int i = 0; i < n; ++i) {
      pascal[i] = std::vector<long long>(i + 1, 1);
      for (int j = 1; j < i; ++j) {
        pascal[i][j] = (pascal[i - 1][j - 1] + pascal[i - 1][j]) % kMod;
      }
    }

    return numsOfWays(nums, pascal) - 1;
  }

private:
  static const int kMod = 1e9 + 7;

  static long numsOfWays(const std::vector<int> &nums,
                         const std::vector<std::vector<long long>> &pascal) {
    const int n = nums.size();

    if (n < 3) {
      return 1;
    }

    std::vector<int> left, right;
    for (int i = 1; i < n; ++i) {
      if (nums[i] < nums[0]) {
        left.push_back(nums[i]);
      } else {
        right.push_back(nums[i]);
      }
    }

    long long ways = pascal[n - 1][left.size()];
    ways = (numsOfWays(left, pascal) * ways) % kMod;
    ways = (numsOfWays(right, pascal) * ways) % kMod;
    return ways;
  }
};
