#pragma once

#include <vector>

// Time: O(N)
// Space: O(1)

namespace brute_force {

// Time: O(N^2)
// Space: O(N)
class Solution {
public:
  static int triangularSum(std::vector<int> nums) {
    for (int n = nums.size(); n > 0; --n) {
      for (int j = 0; j + 1 < n; ++j) {
        nums[j] = (nums[j] + nums[j + 1]) % 10;
      }
    }
    return nums[0];
  }
};

} // namespace brute_force

namespace math {

class IntMod10 {
public:
  IntMod10(int val) : val(val % 10) {}

  operator int() const {
    return val * (pows[5] ? 5 : 1) * (1 << (pows[2] - 1) % 4 + 1) % 10;
  }

  IntMod10 &operator*=(int a) {
    for (int p : {2, 5}) {
      for (; a && a % p == 0; a /= p) {
        ++pows[p];
      }
    }
    val = (val * a) % 10;
    return *this;
  }

  IntMod10 &operator/=(int a) {
    static const std::array<int, 10> inv{0, 1, 0, 7, 0, 0, 0, 3, 0, 9};
    for (int p : {2, 5}) {
      for (; a % p == 0; a /= p) {
        --pows[p];
      }
    }
    val = (val * inv[a % 10]) % 10;
    return *this;
  }

private:
  std::array<int, 6> pows{};
  int val;
};

// Time: O(N)
// Space: O(1)
class Solution {
public:
  static int triangularSum(const std::vector<int> &nums) {
    const int n = nums.size();

    int ans = 0;
    IntMod10 Cnk = 1;
    for (int i = 0; i < n; ++i) {
      ans += nums[i] * Cnk % 10;
      ans %= 10;

      Cnk *= (n - i - 1);
      Cnk /= (i + 1);
    }
    return ans;
  }
};

} // namespace math
