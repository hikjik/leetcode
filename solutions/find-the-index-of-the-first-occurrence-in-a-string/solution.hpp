#pragma once

#include <algorithm>
#include <functional>
#include <string>
#include <vector>

// Time: O(N)
// Space: O(M)
// Notes: [Knuth-Morris-Pratt Algorithm](https://w.wiki/7$3A)

namespace naive {

// Time: O(NM)
// Space: O(1)
class Solution {
public:
  static int strStr(std::string haystack, std::string needle) {
    return haystack.find(needle);
  }
};

} // namespace naive

namespace boyer_moore {

// Time: O(NM) in the worst case, O(N) on average
// Space: O(M)
// [Boyer-Moore](https://w.wiki/3ao2)
class Solution {
public:
  static int strStr(std::string haystack, std::string needle) {
    const auto searcher =
        std::boyer_moore_searcher(needle.begin(), needle.end());
    auto it = std::search(haystack.begin(), haystack.end(), searcher);
    return it == haystack.end() ? -1 : std::distance(haystack.begin(), it);
  }
};

} // namespace boyer_moore

namespace boyer_moore_horspool {

// Time: O(NM) in the worst case, O(N) on average
// Space: O(M)
// [Boyer-Moore-Horspool](https://w.wiki/7$hh)
class Solution {
public:
  static int strStr(std::string haystack, std::string needle) {
    const auto searcher =
        std::boyer_moore_horspool_searcher(needle.begin(), needle.end());
    auto it = std::search(haystack.begin(), haystack.end(), searcher);
    return it == haystack.end() ? -1 : std::distance(haystack.begin(), it);
  }
};

} // namespace boyer_moore_horspool

namespace knuth_morris_pratt {

// Time: O(N)
// Space: O(M)
// [Knuth-Morris-Pratt Algorithm](https://w.wiki/7$3A)
class Solution {
public:
  static int strStr(std::string haystack, std::string needle) {
    int n = haystack.size(), m = needle.size();
    if (n < m) {
      return -1;
    }

    const auto lps = LPS(needle);

    int i = 0, j = 0;
    while (i < n) {
      if (haystack[i] == needle[j]) {
        i++, j++;
        if (j == m) {
          return i - m;
        }
      } else {
        if (j) {
          j = lps[j - 1];
        } else {
          ++i;
        }
      }
    }
    return -1;
  }

private:
  static std::vector<int> LPS(const std::string &str) {
    std::vector<int> lps(str.size(), 0);
    for (size_t i = 1; i < str.size(); ++i) {
      int j = lps[i - 1];
      while (j && str[j] != str[i]) {
        j = lps[j - 1];
      }
      if (str[i] == str[j]) {
        ++j;
      }
      lps[i] = j;
    }
    return lps;
  }
};

} // namespace knuth_morris_pratt
