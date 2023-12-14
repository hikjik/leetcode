#pragma once

#include <string>
#include <string_view>
#include <unordered_map>
#include <vector>

// N is the length of the string s
// K is the length of the array knowledge
// Time: O(N+K)
// Space: O(K)

class Solution {
public:
  static std::string
  evaluate(std::string s,
           const std::vector<std::vector<std::string>> &knowledge) {
    std::unordered_map<std::string_view, std::string_view> map;
    for (const auto &p : knowledge) {
      map[p[0]] = p[1];
    }

    std::string ans;
    const std::string_view sv(s);
    for (int i = 0; i < std::ssize(sv); ++i) {
      if (sv[i] == '(') {
        const auto j = sv.find_first_of(')', i + 1);
        const auto name = sv.substr(i + 1, j - i - 1);

        if (auto it = map.find(name); it != map.end()) {
          ans += it->second;
        } else {
          ans += '?';
        }

        i = j;
      } else {
        ans += sv[i];
      }
    }
    return ans;
  }
};
