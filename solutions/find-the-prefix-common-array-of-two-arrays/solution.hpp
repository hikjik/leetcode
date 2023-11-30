#pragma once

#include <vector>

// Time: O(N)
// Space: O(N)

class Solution {
public:
  static std::vector<int> findThePrefixCommonArray(const std::vector<int> &A,
                                                   const std::vector<int> &B) {
    std::vector<bool> seen(A.size() + 1);
    std::vector<int> ans;
    for (int cnt = 0, i = 0; i < std::ssize(A); ++i) {
      cnt += seen[A[i]] + seen[B[i]] + (A[i] == B[i]);
      ans.push_back(cnt);
      seen[A[i]] = seen[B[i]] = true;
    }
    return ans;
  }
};
