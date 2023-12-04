#pragma once

#include <sstream>
#include <stack>
#include <string>

// Time: O(N)
// Space: O(N)

class Solution {
public:
  static int lengthLongestPath(std::string input) {
    std::stringstream istream(input);
    std::stack<int> stack{{-1}};
    int ans = 0;
    for (std::string token; std::getline(istream, token, '\n');) {
      const int depth =
          token.starts_with('\t') ? token.find_first_not_of('\t') : 0;
      while (depth + 1 < std::ssize(stack)) {
        stack.pop();
      }
      const int length = std::ssize(token) - depth + stack.top() + 1;
      if (token.find('.') != std::string::npos) {
        ans = std::max(ans, length);
      } else {
        stack.push(length);
      }
    }
    return ans;
  }
};
