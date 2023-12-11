#pragma once

#include <algorithm>
#include <cmath>
#include <vector>

// Time: O(NlogN)
// Space: O(N)

class Solution {
public:
  static long long makeSimilar(std::vector<int> nums, std::vector<int> target) {
    sortEvenOdd(nums.begin(), nums.end());
    sortEvenOdd(target.begin(), target.end());

    long long ans = 0;
    for (int i = 0; i < std::ssize(nums); ++i) {
      ans += std::abs(nums[i] - target[i]);
    }
    return ans / 4;
  }

private:
  using Iterator = std::vector<int>::iterator;

  static void sortEvenOdd(Iterator first, Iterator last) {
    auto middle = std::partition(first, last, [](int a) { return a & 1; });
    std::sort(first, middle);
    std::sort(middle, last);
  }
};
