#pragma once

#include <string>
#include <string_view>
#include <vector>

// Time: O(N+K)
// Space: O(N+K)

namespace naive {

// Time: O(N^2K)
// Space: O(1)
class Solution {
public:
  static std::string removeOccurrences(std::string s, std::string part) {
    for (auto pos = s.find(part); pos != std::string::npos;
         pos = s.find(part)) {
      s.erase(pos, part.size());
    }
    return s;
  }
};

} // namespace naive

namespace stack {

// Time: O(NK)
// Space: O(1)
class Solution {
public:
  static std::string removeOccurrences(std::string s, std::string part) {
    const int k = part.size();
    const std::string_view sv(s);

    int size = 0;
    for (auto c : s) {
      s[size++] = c;
      if (size >= k && sv.substr(size - k, k) == part) {
        size -= k;
      }
    }
    return s.substr(0, size);
  }
};

} // namespace stack

namespace kmp {

// Time: O(N+K)
// Space: O(N+K)
class Solution {
public:
  static std::string removeOccurrences(std::string s, std::string part) {
    const int k = part.size();
    const auto lps = LPS(part);

    std::vector<int> idx(s.size(), 0);

    int size = 0;
    for (int i = 0, j = 0; i < std::ssize(s);) {
      if (s[i] == part[j]) {
        idx[size] = ++j;
        s[size++] = s[i++];
        if (j == k) {
          size -= k;
          j = size ? idx[size - 1] : 0;
        }
      } else {
        if (j) {
          j = lps[j - 1];
        } else {
          idx[size] = 0;
          s[size++] = s[i++];
        }
      }
    }
    return s.substr(0, size);
  }

private:
  static std::vector<int> LPS(const std::string &s) {
    std::vector<int> lps(s.size());
    for (int i = 1, j = 0; i < std::ssize(s);) {
      if (s[i] == s[j]) {
        lps[i++] = ++j;
      } else {
        if (j) {
          j = lps[j - 1];
        } else {
          ++i;
        }
      }
    }
    return lps;
  }
};

} // namespace kmp
