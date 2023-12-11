#pragma once

#include <stack>
#include <vector>

// Time: O(N)
// Space: O(N)

class Solution {
public:
  struct Item {
    int len;
    long long last;
    long long ps;
  };

  // len[j] is the maximum number of elements in the increasing sequence after
  //        processing the first j elements nums[0], nums[1], ..., nums[j]
  // last[j] is the last element in the increasing sequence after
  //         processing the first j elements
  // ps[j] = nums[0] + ... nums[j]
  //
  // len[j] = 1 + len[i] if nums[i+1] + ... + nums[j] >= last[i]
  //                                 or ps[j] - ps[i] >= last[i]
  //                                 or ps[j] >= last[i] + ps[i]

  static int findMaximumLength(const std::vector<int> &nums) {
    std::vector<Item> dp{{0, 0, 0}};

    size_t i = 0;
    for (long long ps = 0; auto a : nums) {
      ps += a;
      while (i + 1 < dp.size() && ps >= dp[i + 1].last + dp[i + 1].ps) {
        ++i;
      }

      const auto last = ps - dp[i].ps;
      const auto len = 1 + dp[i].len;
      while (!dp.empty() && ps + last < dp.back().ps + dp.back().last) {
        if (i + 1 == dp.size()) {
          --i;
        }
        dp.pop_back();
      }
      dp.push_back({len, last, ps});
    }
    return dp.back().len;
  }
};
