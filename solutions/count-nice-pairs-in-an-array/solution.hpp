#pragma once

#include <unordered_map>
#include <vector>

// Time: O(NlogM), where logM is the complexity of reversing a number
// Space: O(N)

class Solution {
public:
  static constexpr int kMod = 1e9 + 7;

  static int countNicePairs(const std::vector<int> &nums) {
    std::unordered_map<int, int> map;
    long long ans = 0;
    for (auto num : nums) {
      ans += map[num - reverse(num)]++;
    }
    return ans % kMod;
  }

private:
  static int reverse(int n) {
    int ans = 0;
    for (int i = n; i; i /= 10) {
      ans = ans * 10 + i % 10;
    }
    return ans;
  }
};
