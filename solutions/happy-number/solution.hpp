#pragma once

#include <cmath>
#include <unordered_set>

// Time: O(logN)
// Space: O(1)
// Notes: [Floyd's Cycle](https://w.wiki/8Mdx)

namespace hash_table {

// Time: O(logN)
// Space: O(logN)
class Solution {
public:
  static bool isHappy(int n) {
    std::unordered_set<int> set;
    for (; !set.contains(n); n = next(n)) {
      set.insert(n);
    }
    return set.contains(1);
  }

private:
  static int next(int n) {
    int sum = 0;
    for (; n; n /= 10) {
      sum += std::pow(n % 10, 2);
    }
    return sum;
  }
};

} // namespace hash_table

namespace slow_fast {

// Time: O(logN)
// Space: O(1)
class Solution {
public:
  static bool isHappy(int n) {
    int slow = n, fast = next(n);
    while (slow != fast) {
      slow = next(slow);
      fast = next(next(fast));
    }
    return slow == 1;
  }

private:
  static int next(int n) {
    int sum = 0;
    for (; n; n /= 10) {
      sum += std::pow(n % 10, 2);
    }
    return sum;
  }
};

} // namespace slow_fast
