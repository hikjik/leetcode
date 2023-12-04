#pragma once

#include <vector>

// Time: O(N)
// Space: O(1)

class Solution {
public:
  static std::vector<int> lexicalOrder(int n) {
    std::vector<int> ans;
    int num = 1;
    while (std::ssize(ans) < n) {
      ans.push_back(num);
      if (num * 10 <= n) {
        num *= 10;
      } else {
        while (num % 10 == 9 || num == n) {
          num /= 10;
        }
        ++num;
      }
    }
    return ans;
  }
};
