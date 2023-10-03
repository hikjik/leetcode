#pragma once

#include <array>
#include <vector>

class Solution {
private:
  static constexpr size_t kMaxNum = 100;

public:
  static int numIdenticalPairs(const std::vector<int> &nums) {
    int cnt = 0;
    std::array<int, kMaxNum + 1> freq{};
    for (auto a : nums) {
      cnt += freq[a]++;
    }
    return cnt;
  }
};
