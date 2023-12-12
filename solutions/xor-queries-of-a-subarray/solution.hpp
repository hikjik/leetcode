#pragma once

#include <numeric>
#include <vector>

// Time: O(N+Q)
// Space: O(N)

class Solution {
public:
  static std::vector<int>
  xorQueries(const std::vector<int> &arr,
             const std::vector<std::vector<int>> &queries) {
    std::vector<int> ps(arr.size() + 1);
    std::partial_sum(arr.begin(), arr.end(), ps.begin() + 1, std::bit_xor{});

    std::vector<int> ans(queries.size());
    for (int i = 0; i < std::ssize(queries); ++i) {
      ans[i] = ps[queries[i][1] + 1] ^ ps[queries[i][0]];
    }
    return ans;
  }
};
