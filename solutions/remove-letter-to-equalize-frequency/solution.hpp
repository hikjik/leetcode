#pragma once

#include <algorithm>
#include <string>
#include <vector>

/*
  2423. Remove Letter To Equalize Frequency
  https://leetcode.com/problems/remove-letter-to-equalize-frequency/
  Difficulty: Easy
  Tags: Hash Table, String, Counting
  Time:
  Space:
*/

class Solution {
public:
  static bool equalFrequency(std::string word) {
    std::vector<int> counter(26);
    for (auto c : word) {
      ++counter[c - 'a'];
    }

    std::vector<int> freq;
    std::copy_if(counter.begin(), counter.end(), std::back_inserter(freq),
                 [](int a) { return a; });
    std::sort(freq.begin(), freq.end());
    const int n = freq.size();
    if (n == 1) {
      return true;
    }
    if (freq[0] == freq[n - 2] && freq[0] + 1 == freq[n - 1]) {
      return true;
    }
    if (freq[0] == 1 && freq[1] == freq[n - 1]) {
      return true;
    }
    return false;
  }
};
