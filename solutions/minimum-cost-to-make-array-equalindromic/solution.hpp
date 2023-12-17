#pragma once

#include <climits>
#include <cmath>
#include <ranges>
#include <vector>

// Time: O(NlogN)
// Space: O(N)

class Solution {
public:
  static long long minimumCost(const std::vector<int> &nums) {
    long long ans = LONG_MAX;
    for (auto p : nearestPalindromes(median(nums))) {
      long long sum = 0;
      for (auto num : nums) {
        sum += std::abs(num - p);
      }
      ans = std::min(ans, sum);
    }
    return ans;
  }

private:
  static int median(std::vector<int> nums) {
    std::ranges::nth_element(nums, nums.begin() + nums.size() / 2);
    return nums[nums.size() / 2];
  }

  static std::vector<int> nearestPalindromes(int n) {
    std::vector<int> palindromes(2, n);
    while (!isPalindrome(palindromes[0])) {
      --palindromes[0];
    }
    while (!isPalindrome(palindromes[1])) {
      ++palindromes[1];
    }
    return palindromes;
  }

  static bool isPalindrome(int n) { return n == reverse(n); }

  static int reverse(int n) {
    int r = 0;
    for (int i = n; i; i /= 10) {
      r = r * 10 + i % 10;
    }
    return r;
  }
};
