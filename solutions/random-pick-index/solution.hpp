#pragma once

#include <random>
#include <unordered_map>
#include <vector>

// Time: O(N+Q)
// Space: (N)

class Solution {
public:
  // O(N)
  Solution(const std::vector<int> &nums) : gen(std::random_device()()) {
    for (int i = 0; i < std::ssize(nums); ++i) {
      buckets[nums[i]].push_back(i);
    }
  }
  // O(1)
  int pick(int target) {
    const auto &bucket = buckets[target];
    std::uniform_int_distribution<int> distr(0, bucket.size() - 1);
    return bucket[distr(gen)];
  }

private:
  std::unordered_map<int, std::vector<int>> buckets;
  std::mt19937 gen;
};
