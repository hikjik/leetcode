#pragma once

#include <string>

// Time:
// Space:

class Solution {
public:
  static std::string reformatNumber(std::string number) {
    std::string ans;
    for (int cnt = 0; auto c : number) {
      if (std::isdigit(c)) {
        if (cnt && cnt % 3 == 0) {
          ans.push_back('-');
        }
        ++cnt;
        ans.push_back(c);
      }
    }

    if (ans[ans.size() - 2] == '-') {
      std::swap(ans[ans.size() - 2], ans[ans.size() - 3]);
    }
    return ans;
  }
};
