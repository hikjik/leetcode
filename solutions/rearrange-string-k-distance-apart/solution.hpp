#pragma once

#include <queue>
#include <string>

// Time: O(NlogA)
// Space: O(min(A,K))

class Solution {
public:
  static std::string rearrangeString(std::string s, int k) {
    std::array<int, 128> cnt{};
    for (auto c : s) {
      ++cnt[c];
    }

    auto less = [&](char a, char b) { return cnt[a] < cnt[b]; };
    std::priority_queue<char, std::vector<char>, decltype(less)> free(less);
    for (auto c = 'a'; c <= 'z'; ++c) {
      if (cnt[c]) {
        free.push(c);
      }
    }

    std::string ans;
    std::queue<char> busy;
    for (int i = 0; i < std::ssize(s); ++i) {
      if (free.empty()) {
        return "";
      }

      const auto c = free.top();
      free.pop();

      ans += c;
      busy.push(c);
      --cnt[c];

      if (i >= k - 1) {
        if (cnt[busy.front()]) {
          free.push(busy.front());
        }
        busy.pop();
      }
    }
    return ans;
  }
};
