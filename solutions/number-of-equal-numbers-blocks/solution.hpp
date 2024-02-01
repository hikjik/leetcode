#pragma once

#include <vector>

// Time: O(logN)
// Space: O(logN)

class BigArray {
public:
  explicit BigArray(std::vector<int> elements)
      : elements(std::move(elements)) {}

  int at(long long index) const { return elements[index]; }

  long long size() const { return elements.size(); }

private:
  std::vector<int> elements;
};

namespace dac {

// Time: O(logN)
// Space: O(logN)
class Solution {
public:
  static int countBlocks(BigArray *nums) {
    return countBlocks(nums, 0, nums->size() - 1);
  }

private:
  static int countBlocks(BigArray *nums, long long left, long long right) {
    if (nums->at(left) == nums->at(right)) {
      return 1;
    }
    const auto middle = left + (right - left) / 2;
    return countBlocks(nums, left, middle) +
           countBlocks(nums, middle + 1, right) -
           (nums->at(middle) == nums->at(middle + 1));
  }
};

} // namespace dac

namespace bs {

// M is number of unique elements in nums
// Time: O(MlogN)
// Space: O(1)
class Solution {
public:
  static int countBlocks(BigArray *nums) {
    int ans = 0;
    for (long long i = 0; i < nums->size(); ++ans) {
      auto l = i, r = nums->size();
      while (l < r) {
        const auto m = l + (r - l) / 2;
        nums->at(m) == nums->at(i) ? l = m + 1 : r = m;
      }
      i = r;
    }
    return ans;
  }
};

} // namespace bs
