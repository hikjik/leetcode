#pragma once

#include <ranges>
#include <vector>

// Time: O(logN)
// Space: O(1)

class ArrayReader {
public:
  explicit ArrayReader(const std::vector<int> &nums) : size(nums.size()) {
    pos = std::ranges::max_element(nums) - nums.begin();
  }

  int compareSub(int l, int r, int x, int y) {
    ++calls;
    const int left = l <= pos && pos <= r;
    const int right = x <= pos && pos <= y;
    if (left < right) {
      return -1;
    }
    if (left > right) {
      return 1;
    }
    return 0;
  }

  // Returns the length of the array
  int length() const { return size; }

  int numOfCalls() const { return calls; }

private:
  int size = 0;
  int pos = 0;
  int calls = 0;
};

class Solution {
public:
  static int getIndex(ArrayReader &reader) {
    int l = 0, r = reader.length() - 1;
    while (l < r) {
      const auto m = l + (r - l) / 2;
      const auto odd = (r - l) & 1;
      const auto ans = reader.compareSub(l, m, m + odd, r);
      if (!ans) {
        return m;
      }
      ans == 1 ? r = m : l = m + 1;
    }
    return l;
  }
};
