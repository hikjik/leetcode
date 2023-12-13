#pragma once

#include <array>
#include <string>
#include <unordered_set>

// Time: O(N)
// Space: O(A)

namespace hash_table {

// Time: O(N)
// Space: O(N)
class Solution {
public:
  static int numSplits(std::string s) {
    std::vector<int> prefix(s.size()), suffix(s.size());
    countUnique(s.cbegin(), s.cend(), prefix.begin());
    countUnique(s.crbegin(), s.crend(), suffix.rbegin());

    int ans = 0;
    for (int i = 0; i + 1 < std::ssize(s); ++i) {
      ans += prefix[i] == suffix[i + 1];
    }
    return ans;
  }

private:
  template <typename InputIterator, typename OutputIterator>
  static void countUnique(InputIterator first, InputIterator last,
                          OutputIterator out) {
    std::unordered_set<int> seen;
    for (auto it = first; it != last; ++it) {
      seen.insert(*it);
      *out++ = seen.size();
    }
  }
};

} // namespace hash_table

namespace sliding_window {

// Time: O(N)
// Space: O(A)
class Solution {
public:
  static int numSplits(std::string s) {
    std::array<int, 26> freqL{}, freqR{};
    int cntL = 0, cntR = 0;
    for (auto c : s) {
      cntR += !freqR[c - 'a']++;
    }

    int ans = 0;
    for (auto c : s) {
      cntL += !freqL[c - 'a']++;
      cntR -= !--freqR[c - 'a'];
      ans += cntL == cntR;
    }
    return ans;
  }
};

} // namespace sliding_window
