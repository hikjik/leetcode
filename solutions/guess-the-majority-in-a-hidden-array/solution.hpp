#pragma once

// Time: O(N)
// Space: O(1)

#include <vector>

class ArrayReader {
public:
  explicit ArrayReader(std::vector<int> nums) : nums(std::move(nums)) {}

  int query(int a, int b, int c, int d) const {
    assert(0 <= a && a < b && b < c && c < d && d < std::ssize(nums));

    ++calls;
    const auto sum = nums[a] + nums[b] + nums[c] + nums[d];
    if (sum == 4 || sum == 0) {
      return 4;
    }
    if (sum == 2) {
      return 0;
    }
    return 2;
  }

  int length() const { return nums.size(); }

  int getNumberOfCalls() const { return calls; }

private:
  mutable int calls = 0;
  std::vector<int> nums;
};

class Solution {
public:
  static int guessMajority(ArrayReader &reader) {
    const int n = reader.length();

    int cnt = 0;  // count idx : nums[idx] != nums[0]
    int idx = -1; // store idx : nums[idx] != nums[0]

    const auto q0123 = reader.query(0, 1, 2, 3);
    const auto q1234 = reader.query(1, 2, 3, 4);

    if (reader.query(0, 2, 3, 4) != q1234) {
      ++cnt;
      idx = 1;
    }
    if (reader.query(0, 1, 3, 4) != q1234) {
      ++cnt;
      idx = 2;
    }
    if (reader.query(0, 1, 2, 4) != q1234) {
      ++cnt;
      idx = 3;
    }
    if (q0123 != q1234) {
      ++cnt;
      idx = 4;
    }

    for (int i = 5; i < n; ++i) {
      if (q0123 != reader.query(1, 2, 3, i)) {
        ++cnt;
        idx = i;
      }
    }
    return cnt > n - cnt ? idx : cnt < n - cnt ? 0 : -1;
  }
};
