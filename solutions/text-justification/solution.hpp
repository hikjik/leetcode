#pragma once

#include <string>
#include <vector>

// N is the number of words, M is the max length of word, W is maxWidth
// Time: O(NM)
// Space: O(W)

class Solution {
public:
  static std::vector<std::string>
  fullJustify(const std::vector<std::string> &words, int maxWidth) {
    std::vector<std::string> ans;
    for (auto left = words.begin(), right = left; left != words.end();) {
      auto slots = maxWidth, words_count = 0;
      while (right != words.end() &&
             slots >= words_count + std::ssize(*right)) {
        slots -= std::ssize(*right++);
        ++words_count;
      }

      std::string line = *left++;
      const auto gaps = words_count - 1;
      for (int i = 0; left != right; ++i) {
        if (right == words.end()) {
          line += ' ';
        } else {
          line.append(slots / gaps + (i < slots % gaps), ' ');
        }
        line += *left++;
      }
      line.append(maxWidth - std::ssize(line), ' ');
      ans.push_back(std::move(line));
    }
    return ans;
  }
};
