#pragma once

#include <algorithm>
#include <string>
#include <unordered_map>

// Time: O(N)
// Space: O(A), where A is the size of the alphabet

namespace sliding_window {

// Time: O(N)
// Space: O(A)
// Sliding Window
class Solution {
public:
  static int lengthOfLongestSubstring(std::string s) {
    std::unordered_map<char, int> counter;
    int length = 0;
    for (int i = 0, j = 0; j < std::ssize(s); ++j) {
      ++counter[s[j]];
      while (counter[s[j]] > 1) {
        --counter[s[i++]];
      }
      length = std::max(length, j - i + 1);
    }
    return length;
  }
};

} // namespace sliding_window

namespace hash_table {

// Time: O(N)
// Space: O(A)
// Hash Table
class Solution {
public:
  static int lengthOfLongestSubstring(std::string s) {
    std::unordered_map<char, int> last_seen;
    int length = 0;
    for (int i = 0, j = 0; j < std::ssize(s); ++j) {
      if (last_seen.contains(s[j])) {
        i = std::max(i, last_seen[s[j]] + 1);
      }
      length = std::max(length, j - i + 1);
      last_seen[s[j]] = j;
    }
    return length;
  }
};

} // namespace hash_table
